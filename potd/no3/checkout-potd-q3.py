#!/usr/bin/env python
from contextlib import closing
import os
import sys
import tarfile

if sys.version_info[0] < 3:
    import ConfigParser as configparser
    from urllib2 import Request, urlopen, URLError, HTTPError
else:
    import configparser
    from urllib.request import Request, urlopen, URLError, HTTPError

dir_name = 'potd-q3'
archive_name = 'potd-q3.tar.gz'
upload_file = 'q3.cpp'

red = lambda s: '\033[31m%s\033[39m' % s
green = lambda s: '\033[32m%s\033[39m' % s
underline = lambda s: '\033[4m%s\033[24m' % s

base_url = """https://prairielearn.engr.illinois.edu/backend/cs225"""
auth_uid = """agrawl10@illinois.edu"""
auth_name = """Aahan Agrawal"""
auth_date = """2016-08-31T19:40:22-05:00"""
auth_signature = """729d2267ae21b09c95383c985266393806466522528aec9aa001e4ee7d5bcc54"""

user_uid = """agrawl10@illinois.edu"""
qid = """potd-q3"""
qiid = """qi2854"""
tiid = """ti2014"""

if os.path.isdir(dir_name):
    print('%s: You have already checked out the problem code.' % (
        red(underline('Error'))))
    if sys.version_info[0] < 3:
        response = raw_input('Overwrite existing code? [yes/no] ')
    else:
        response = input('Overwrite existing code? [yes/no] ')
    if response != 'yes':
        if response != 'no':
            print('Invalid response. Exiting.')
        sys.exit(1)

url = '%s/qInstances/%s/%s' % (base_url, qiid, archive_name)
headers = {
    'X-Auth-UID': auth_uid,
    'X-Auth-Name': auth_name,
    'X-Auth-Date': auth_date,
    'X-Auth-Signature': auth_signature,
}
req = Request(url, headers=headers)

try:
    f = urlopen(req)
except URLError as e:
    sys.exit('%s: %s' % (red(underline('Error')), e.reason))
except HTTPError as e:
    sys.exit('%s: %s' % (red(underline('Error')), e.read()))

with closing(tarfile.open(fileobj=f, mode='r|gz')) as tar:
    tar.extractall()

config = configparser.RawConfigParser()

config.add_section('PrairieLearn')
config.set('PrairieLearn', 'base_url', base_url)

config.add_section('Authentication')
config.set('Authentication', 'auth_uid', auth_uid)
config.set('Authentication', 'auth_name', auth_name)
config.set('Authentication', 'auth_date', auth_date)
config.set('Authentication', 'auth_signature', auth_signature)

config.add_section('Question')
config.set('Question', 'user_uid', user_uid)
config.set('Question', 'qid', qid)
config.set('Question', 'qiid', qiid)
config.set('Question', 'tiid', tiid)
config.set('Question', 'upload_file', upload_file)

with open(dir_name + '/.pl_upload.cfg', 'w') as configfile:
    config.write(configfile)

print('Problem code has been checked out to %s.' % green(os.path.abspath(dir_name)))
print('Run `make upload` to upload your code to PrairieLearn.')
