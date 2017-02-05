/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
  // change this

    vector<Vertex> vertices = graph.getVertices();
    for (Vertex v: vertices)
    {
      graph.setVertexLabel(v, "UNEXPLORED");
    }

    vector<Edge> edges = graph.getEdges();
    for (Edge e: edges)
    {
      e.label = "UNEXPLORED";
    }

    stack<Vertex> verts;
    int minWeight = INT_MAX;
    Vertex start; Vertex end;
    bool first = true;
    verts.push(graph.getStartingVertex());
    Vertex current;

    while (!verts.empty())
    {
      current = verts.top();
      verts.pop();
      graph.setVertexLabel(current, "VISITED");

      vector<Vertex> adjacent = graph.getAdjacent(current);
      for (Vertex v: adjacent)
      {
        if (graph.getVertexLabel(v) == "UNEXPLORED")
        {
          graph.setVertexLabel(v, "VISITED");
          graph.setEdgeLabel(current, v, "DISCOVERY");
          verts.push(v);
        }
        else
        {
          if (graph.getEdgeLabel(current, v) == "UNEXPLORED")
          {
            graph.setEdgeLabel(current, v, "CROSS");
          }
        }

        if (graph.getEdgeWeight(current, v) < minWeight)
        {
          minWeight = graph.getEdgeWeight(current, v);
          start = current;
          end = v;
        }
      }
    }

    graph.setEdgeLabel(start, end, "MIN");
    return minWeight;
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
  vector<Vertex> vertices = graph.getVertices();
  for (Vertex v: vertices)
  {
    graph.setVertexLabel(v, "UNEXPLORED");
  }

  vector<Edge> edges = graph.getEdges();
  for (Edge e: edges)
  {
    e.label = "UNEXPLORED";
  }

  queue<Vertex> verts;
  verts.push(start);
  graph.setVertexLabel(start, "VISITED");

  Vertex current;
  unordered_map<Vertex, Vertex> parents;

  while (!verts.empty())
  {
    current = verts.front();
    verts.pop();

    vector<Vertex> adjacent = graph.getAdjacent(current);
    for (Vertex v: adjacent)
    {
      if (graph.getVertexLabel(v) == "UNEXPLORED")
      {
        graph.setVertexLabel(v, "VISITED");
        graph.setEdgeLabel(current, v, "DISCOVERY");
        verts.push(v);
        parents.insert({v, current});
      }
      else
      {
        if (graph.getEdgeLabel(current, v) == "UNEXPLORED")
        {
          graph.setEdgeLabel(current, v, "CROSS");
        }
      }
    }
  }

  int minPath = 0;
  current = end;
  while (current != start)
  {
    minPath++;
    graph.setEdgeLabel(current, parents[current], "MINPATH");
    current = parents[current];
  }

  return minPath;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{

    vector<Vertex> entries = graph.getVertices();
    DisjointSets s;
    int n = entries.size();
    s.addelements(n);
    unordered_map<Vertex, int> vertexMap;
    int i = 0;
    for (Vertex v: entries)
    {
      vertexMap.insert({v, i});
      i++;
    }

    vector<Edge> edges = graph.getEdges();
    sort(edges.begin(), edges.end());

    int count = 0;
    i = 0;
    Edge current;
    while (count != n-1)
    {
      current = edges[i];
      if (s.find(vertexMap[current.source]) != s.find(vertexMap[current.dest]))
      {
        count++;
        s.setunion(vertexMap[current.source],vertexMap[current.dest]);
        graph.setEdgeLabel(current.source, current.dest, "MST");
      }
      i++;
    }

}
