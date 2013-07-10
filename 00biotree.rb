#
# = bio/pathway.rb - Binary relations and Graph algorithms
#
# Copyright:    Copyright (C) 2001
#               Toshiaki Katayama <k@bioruby.org>,
#               Shuichi Kawashima <shuichi@hgc.jp>
# License::     The Ruby License
#
#  $Id:$
#

require 'matrix'

module Bio

# Bio::Pathway is a general graph object initially constructed by the
# list of the ((<Bio::Relation>)) objects.  The basic concept of the
# Bio::Pathway object is to store a graph as an adjacency list (in the
# instance variable @graph), and converting the list into an adjacency
# matrix by calling to_matrix method on demand.  However, in some
# cases, it is convenient to have the original list of the
# ((<Bio::Relation>))s, Bio::Pathway object also stores the list (as
# the instance variable @relations) redundantly.
# 
# Note: you can clear the @relations list by calling clear_relations!
# method to reduce the memory usage, and the content of the @relations
# can be re-generated from the @graph by to_relations method.
class Pathway

  # Initial graph (adjacency list) generation from the list of Relation.
  # 
  # Generate Bio::Pathway object from the list of Bio::Relation objects.
  # If the second argument is true, undirected graph is generated.
  #
  #   r1 = Bio::Relation.new('a', 'b', 1)
  #   r2 = Bio::Relation.new('a', 'c', 5)
  #   r3 = Bio::Relation.new('b', 'c', 3)
  #   list = [ r1, r2, r3 ]
  #   g = Bio::Pathway.new(list, 'undirected')
  #
  def initialize(relations, undirected = false)
    @undirected = undirected
    @relations = relations
    @graph = {}		# adjacency list expression of the graph
    @index = {}		# numbering each node in matrix
    @label = {}		# additional information on each node
    self.to_list		# generate adjacency list
  end

  # Read-only accessor for the internal list of the Bio::Relation objects
  attr_reader :relations

  # Read-only accessor for the adjacency list of the graph.
  attr_reader :graph

  # Read-only accessor for the row/column index (@index) of the
  # adjacency matrix.  Contents of the hash @index is created by
  # calling to_matrix method.
  attr_reader :index

  # Accessor for the hash of the label assigned to the each node.  You can
  # label some of the nodes in the graph by passing a hash to the label
  # and select subgraphs which contain labeled nodes only by subgraph method.
  #
  #   hash = { 1 => 'red', 2 => 'green', 5 => 'black' }
  #   g.label = hash
  #   g.label
  #   g.subgraph    # => new graph consists of the node 1, 2, 5 only
  #
  attr_accessor :label


  # Returns true or false respond to the internal state of the graph.
  def directed?
    @undirected ? false : true
  end

  # Returns true or false respond to the internal state of the graph.
  def undirected?
    @undirected ? true : false
  end

  # Changes the internal state of the graph from 'undirected' to
  # 'directed' and re-generate adjacency list.  The undirected graph
  # can be converted to directed graph, however, the edge between two
  # nodes will be simply doubled to both ends.
  #
  # Note: this method can not be used without the list of the
  # Bio::Relation objects (internally stored in @relations variable).
  # Thus if you already called clear_relations! method, call
  # to_relations first.
  def directed
    if undirected?
      @undirected = false
      self.to_list
    end
  end

  # Changes the internal state of the graph from 'directed' to
  # 'undirected' and re-generate adjacency list.
  # 
  # Note: this method can not be used without the list of the
  # Bio::Relation objects (internally stored in @relations variable).
  # Thus if you already called clear_relations! method, call
  # to_relations first.
  def undirected
    if directed?
      @undirected = true
      self.to_list
    end
  end

  # Clear @relations array to reduce the memory usage.
  def clear_relations!
    @relations.clear
  end

  # Reconstruct @relations from the adjacency list @graph.
  def to_relations
    @relations.clear
    @graph.each_key do |from|
      @graph[from].each do |to, w|
        @relations << Relation.new(from, to, w)
      end
    end
    return @relations
  end


  # Graph (adjacency list) generation from the Relations
  #
  # Generate the adjcancecy list @graph from @relations (called by
  # initialize and in some other cases when @relations has been changed).
  def to_list
    @graph.clear
    @relations.each do |rel|
      append(rel, false)	# append to @graph without push to @relations
    end
  end

  # Add an Bio::Relation object 'rel' to the @graph and @relations.
  # If the second argument is false, @relations is not modified (only
  # useful when genarating @graph from @relations internally).
  def append(rel, add_rel = true)
    @relations.push(rel) if add_rel
    if @graph[rel.from].nil?
      @graph[rel.from] = {}
    end
    if @graph[rel.to].nil?
      @graph[rel.to] = {}
    end
    @graph[rel.from][rel.to] = rel.relation
    @graph[rel.to][rel.from] = rel.relation if @undirected
  end

  # Remove an edge indicated by the Bio::Relation object 'rel' from the
  # @graph and the @relations.
  def delete(rel)
    @relations.delete_if do |x|
      x === rel
    end
    @graph[rel.from].delete(rel.to)
    @graph[rel.to].delete(rel.from) if @undirected
  end

  # Returns the number of the nodes in the graph.
  def nodes
    @graph.keys.length
  end

  # Returns the number of the edges in the graph.
  def edges
    edges = 0
    @graph.each_value do |v|
      edges += v.size
    end
    edges
  end


  # Convert adjacency list to adjacency matrix
  # 
  # Returns the adjacency matrix expression of the graph as a Matrix
  # object.  If the first argument was assigned, the matrix will be
  # filled with the given value.  The second argument indicates the
  # value of the diagonal constituents of the matrix besides the above.
  #
  # The result of this method depends on the order of Hash#each
  # (and each_key, etc.), which may be variable with Ruby version
  # and Ruby interpreter variations (JRuby, etc.).
  # For a workaround to remove such dependency, you can use @index 
  # to set order of Hash keys. Note that this behavior might be
  # changed in the future. Be careful that @index is overwritten by
  # this method.
  # 
  def to_matrix(default_value = nil, diagonal_value = nil)

    #--
    # Note: following code only fills the outer Array with the reference
    # to the same inner Array object.
    #
    #   matrix = Array.new(nodes, Array.new(nodes))
    #
    # so create a new Array object for each row as follows:
    #++

    matrix = Array.new
    nodes.times do
      matrix.push(Array.new(nodes, default_value))
    end

    if diagonal_value
      nodes.times do |i|
        matrix[i][i] = diagonal_value
      end
    end

    # assign index number
    if @index.empty? then
      # assign index number for each node
      @graph.keys.each_with_index do |k, i|
        @index[k] = i
      end
    else
      # begin workaround removing depencency to order of Hash#each
      # assign index number from the preset @index
      indices = @index.to_a
      indices.sort! { |i0, i1| i0[1] <=> i1[1] }
      indices.collect! { |i0| i0[0] }
      @index.clear
      v = 0
      indices.each do |k, i|
        if @graph[k] and !@index[k] then
          @index[k] = v; v += 1
        end
      end
      @graph.each_key do |k|
        unless @index[k] then
          @index[k] = v; v += 1
        end
      end
      # end workaround removing depencency to order of Hash#each
    end

    if @relations.empty?		# only used after clear_relations!
      @graph.each do |from, hash|
        hash.each do |to, relation|
          x = @index[from]
          y = @index[to]
          matrix[x][y] = relation
        end
      end
    else
      @relations.each do |rel|
        x = @index[rel.from]
        y = @index[rel.to]
        matrix[x][y] = rel.relation
        matrix[y][x] = rel.relation if @undirected
      end
    end
    Matrix[*matrix]
  end


  # Pretty printer of the adjacency matrix.
  #
  # The dump_matrix method accepts the same arguments as to_matrix.
  # Useful when you want to check the internal state of the matrix
  # (for debug purpose etc.) easily.
  #
  # This method internally calls to_matrix method.
  # Read documents of to_matrix for important informations.
  #
  def dump_matrix(*arg)
    matrix = self.to_matrix(*arg)
    sorted = @index.sort {|a,b| a[1] <=> b[1]}
    "[# " + sorted.collect{|x| x[0]}.join(", ") + "\n" +
      matrix.to_a.collect{|row| ' ' + row.inspect}.join(",\n") + "\n]"
  end

  # Pretty printer of the adjacency list.
  # 
  # Useful when you want to check the internal state of the adjacency
  # list (for debug purpose etc.) easily.
  #
  # The result of this method depends on the order of Hash#each
  # (and each_key, etc.), which may be variable with Ruby version
  # and Ruby interpreter variations (JRuby, etc.).
  # For a workaround to remove such dependency, you can use @index 
  # to set order of Hash keys. Note that this behavior might be
  # changed in the future. 
  # 
  def dump_list
    # begin workaround removing depencency to order of Hash#each
    if @index.empty? then
      pref = nil
      enum = @graph
    else
      pref = {}.merge(@index)
      i = pref.values.max
      @graph.each_key do |node|
        pref[node] ||= (i += 1)
      end
      graph_to_a = @graph.to_a
      graph_to_a.sort! { |x, y| pref[x[0]] <=> pref[y[0]] }
      enum = graph_to_a
    end
    # end workaround removing depencency to order of Hash#each

    list = ""
    enum.each do |from, hash|
      list << "#{from} => "
      # begin workaround removing depencency to order of Hash#each
      if pref then
        ary = hash.to_a
        ary.sort! { |x,y| pref[x[0]] <=> pref[y[0]] }
        hash = ary
      end
      # end workaround removing depencency to order of Hash#each
      a = []
      hash.each do |to, relation|
        a.push("#{to} (#{relation})")
      end
      list << a.join(", ") + "\n"
    end
    list
  end

  # Select labeled nodes and generate subgraph
  #
  # This method select some nodes and returns new Bio::Pathway object
  # consists of selected nodes only.  If the list of the nodes (as
  # Array) is assigned as the argument, use the list to select the
  # nodes from the graph.  If no argument is assigned, internal
  # property of the graph @label is used to select the nodes.
  #
  #   hash = { 'a' => 'secret', 'b' => 'important', 'c' => 'important' }
  #   g.label = hash
  #   g.subgraph
  #   list = [ 'a', 'b', 'c' ]
  #    g.subgraph(list)
  #
  def subgraph(list = nil)
    if list
      @label.clear
      list.each do |node|
        @label[node] = true
      end
    end
    sub_graph = Pathway.new([], @undirected)
    @graph.each do |from, hash|
      next unless @label[from]
      sub_graph.graph[from] ||= {}
      hash.each do |to, relation|
        next unless @label[to]
        sub_graph.append(Relation.new(from, to, relation))
      end
    end
    return sub_graph
  end


  # Not implemented yet.
  def common_subgraph(graph)
    raise NotImplementedError
  end


  # Not implemented yet.
  def clique
    raise NotImplementedError
  end


  # Returns completeness of the edge density among the surrounded nodes.
  #
  # Calculates the value of cliquishness around the 'node'.  This value
  # indicates completeness of the edge density among the surrounded nodes.
  #
  # Note: cliquishness (clustering coefficient) for a directed graph
  # is also calculated.
  # Reference: http://en.wikipedia.org/wiki/Clustering_coefficient
  # 
  # Note: Cliquishness (clustering coefficient) for a node that has
  # only one neighbor node is undefined. Currently, it returns NaN,
  # but the behavior may be changed in the future.
  #
  def cliquishness(node)
    neighbors = @graph[node].keys
    sg = subgraph(neighbors)
    if sg.graph.size != 0
      edges = sg.edges
      nodes = neighbors.size
      complete = (nodes * (nodes - 1))
      return edges.quo(complete)
    else
      return 0.0
    end
  end

  # Returns frequency of the nodes having same number of edges as hash
  #
  # Calculates the frequency of the nodes having the same number of edges
  # and returns the value as Hash.
  def small_world
    freq = Hash.new(0)
    @graph.each_value do |v|
      freq[v.size] += 1
    end
    return freq
  end

  # Breadth first search solves steps and path to the each node and
  # forms a tree contains all reachable vertices from the root node.
  # This method returns the result in 2 hashes - 1st one shows the
  # steps from root node and 2nd hash shows the structure of the tree.
  #
  # The weight of the edges are not considered in this method.
  def breadth_first_search(root)
    visited = {}
    distance = {}
    predecessor = {}

    visited[root] = true
    distance[root] = 0
    predecessor[root] = nil

    queue = [ root ]

    while from = queue.shift
      next unless @graph[from]
      @graph[from].each_key do |to|
        unless visited[to]
          visited[to] = true
          distance[to] = distance[from] + 1
          predecessor[to] = from
          queue.push(to)
        end
      end
    end
    return distance, predecessor
  end

  # Alias for the breadth_first_search method.
  alias bfs breadth_first_search


  # Calculates the shortest path between two nodes by using
  # breadth_first_search method and returns steps and the path as Array.
  def bfs_shortest_path(node1, node2)
    distance, route = breadth_first_search(node1)
    step = distance[node2]
    node = node2
    path = [ node2 ]
    while node != node1 and route[node]
      node = route[node]
      path.unshift(node)
    end
    return step, path
  end


  # Depth first search yields much information about the structure of
  # the graph especially on the classification of the edges.  This
  # method returns 5 hashes - 1st one shows the timestamps of each
  # node containing the first discoverd time and the search finished
  # time in an array.  The 2nd, 3rd, 4th, and 5th hashes contain 'tree
  # edges', 'back edges', 'cross edges', 'forward edges' respectively.
  #
  # If $DEBUG is true (e.g. ruby -d), this method prints the progression
  # of the search.
  # 
  # The weight of the edges are not considered in this method.
  #
  # Note: The result of this method depends on the order of Hash#each
  # (and each_key, etc.), which may be variable with Ruby version
  # and Ruby interpreter variations (JRuby, etc.).
  # For a workaround to remove such dependency, you can use @index 
  # to set order of Hash keys. Note that this bahavior might be
  # changed in the future.
  def depth_first_search
    visited = {}
    timestamp = {}
    tree_edges = {}
    back_edges = {}
    cross_edges = {}
    forward_edges = {}
    count = 0

    # begin workaround removing depencency to order of Hash#each
    if @index.empty? then
      preference_of_nodes = nil
    else
      preference_of_nodes = {}.merge(@index)
      i = preference_of_nodes.values.max
      @graph.each_key do |node0|
        preference_of_nodes[node0] ||= (i += 1)
      end
    end
    # end workaround removing depencency to order of Hash#each

    dfs_visit = Proc.new { |from|
      visited[from] = true
      timestamp[from] = [count += 1]
      ary = @graph[from].keys
      # begin workaround removing depencency to order of Hash#each
      if preference_of_nodes then
        ary = ary.sort_by { |node0| preference_of_nodes[node0] }
      end
      # end workaround removing depencency to order of Hash#each
      ary.each do |to|
        if visited[to]
          if timestamp[to].size > 1
            if timestamp[from].first < timestamp[to].first
      	# forward edge (black)
      	p "#{from} -> #{to} : forward edge" if $DEBUG
      	forward_edges[from] = to
            else
      	# cross edge (black)
      	p "#{from} -> #{to} : cross edge" if $DEBUG
      	cross_edges[from] = to
            end
          else
            # back edge (gray)
            p "#{from} -> #{to} : back edge" if $DEBUG
            back_edges[from] = to
          end
        else
          # tree edge (white)
          p "#{from} -> #{to} : tree edge" if $DEBUG
          tree_edges[to] = from
          dfs_visit.call(to)
        end
      end
      timestamp[from].push(count += 1)
    }

    ary = @graph.keys
    # begin workaround removing depencency to order of Hash#each
    if preference_of_nodes then
      ary = ary.sort_by { |node0| preference_of_nodes[node0] }
    end
    # end workaround removing depencency to order of Hash#each
    ary.each do |node|
      unless visited[node]
        dfs_visit.call(node)
      end
    end
    return timestamp, tree_edges, back_edges, cross_edges, forward_edges
  end

  # Alias for the depth_first_search method.
  alias dfs depth_first_search


  # Topological sort of the directed acyclic graphs ("dags") by using
  # depth_first_search.
  def dfs_topological_sort
    # sorted by finished time reversely and collect node names only
    timestamp, = self.depth_first_search
    timestamp.sort {|a,b| b[1][1] <=> a[1][1]}.collect {|x| x.first }
  end


  # Dijkstra method to solve the shortest path problem in the weighted graph.
  def dijkstra(root)
    distance, predecessor = initialize_single_source(root)
    @graph[root].each do |k, v|
      distance[k] = v
      predecessor[k] = root
    end
    queue = distance.dup
    queue.delete(root)

    while queue.size != 0
      min = queue.min {|a, b| a[1] <=> b[1]}
      u = min[0]		# extranct a node having minimal distance
      @graph[u].each do |k, v|
        # relaxing procedure of root -> 'u' -> 'k'
        if distance[k] > distance[u] + v
          distance[k] = distance[u] + v
          predecessor[k] = u
        end
      end
      queue.delete(u)
    end
    return distance, predecessor
  end

  # Bellman-Ford method for solving the single-source shortest-paths
  # problem in the graph in which edge weights can be negative.
  def bellman_ford(root)
    distance, predecessor = initialize_single_source(root)
    (self.nodes - 1).times do
      @graph.each_key do |u|
        @graph[u].each do |v, w|
          # relaxing procedure of root -> 'u' -> 'v'
          if distance[v] > distance[u] + w
            distance[v] = distance[u] + w
            predecessor[v] = u
          end
        end
      end
    end
    # negative cyclic loop check
    @graph.each_key do |u|
      @graph[u].each do |v, w|
        if distance[v] > distance[u] + w
          return false
        end
      end
    end
    return distance, predecessor
  end


  # Floyd-Wardshall alogrithm for solving the all-pairs shortest-paths
  # problem on a directed graph G = (V, E).
  def floyd_warshall
    inf = 1 / 0.0

    m = self.to_matrix(inf, 0)
    d = m.dup
    n = self.nodes
    for k in 0 .. n - 1 do
      for i in 0 .. n - 1 do
        for j in 0 .. n - 1 do
          if d[i, j] > d[i, k] + d[k, j]
            d[i, j] = d[i, k] + d[k, j]
          end
        end
      end
    end
    return d
  end

  # Alias for the floyd_warshall method.
  alias floyd floyd_warshall

  # Kruskal method for finding minimam spaninng trees
  def kruskal
    # initialize
    rel = self.to_relations.sort{|a, b| a <=> b}
    index = []
    for i in 0 .. (rel.size - 1) do
      for j in (i + 1) .. (rel.size - 1) do
        if rel[i] == rel[j]
          index << j
        end
      end
    end
    index.sort{|x, y| y<=>x}.each do |idx|
      rel[idx, 1] = []
    end
    mst = []
    seen = Hash.new()
    @graph.each_key do |x|
      seen[x] = nil
    end
    i = 1
    # initialize end

    rel.each do |r|
      if seen[r.node[0]] == nil
        seen[r.node[0]] = 0
      end
      if seen[r.node[1]] == nil
        seen[r.node[1]] = 0
      end
      if seen[r.node[0]] == seen[r.node[1]] && seen[r.node[0]] == 0
        mst << r
        seen[r.node[0]] = i
        seen[r.node[1]] = i
      elsif seen[r.node[0]] != seen[r.node[1]]
        mst << r
        v1 = seen[r.node[0]].dup
        v2 = seen[r.node[1]].dup
        seen.each do |k, v|
          if v == v1 || v == v2
            seen[k] = i
          end
        end
      end
      i += 1
    end
    return Pathway.new(mst)
  end


  private


  def initialize_single_source(root)
    inf = 1 / 0.0				# inf.infinite? -> true

    distance = {}
    predecessor = {}

    @graph.each_key do |k|
      distance[k] = inf
      predecessor[k] = nil
    end
    distance[root] = 0
    return distance, predecessor
  end

end # Pathway



# Bio::Relation is a simple object storing two nodes and the relation of them.
# The nodes and the edge (relation) can be any Ruby object.  You can also
# compare Bio::Relation objects if the edges have Comparable property.
class Relation

  # Create new binary relation object consists of the two object 'node1'
  # and 'node2' with the 'edge' object as the relation of them.
  def initialize(node1, node2, edge)
    @node = [node1, node2]
    @edge = edge
  end
  attr_accessor :node, :edge

  # Returns one node.
  def from
    @node[0]
  end

  # Returns another node.
  def to
    @node[1]
  end

  def relation
    @edge
  end

  # Used by eql? method
  def hash
    @node.sort.push(@edge).hash
  end

  # Compare with another Bio::Relation object whether havind same edges
  # and same nodes.  The == method compares Bio::Relation object's id,
  # however this case equality === method compares the internal property
  # of the Bio::Relation object.
  def ===(rel)
    if self.edge == rel.edge
      if self.node[0] == rel.node[0] and self.node[1] == rel.node[1]
        return true
      elsif self.node[0] == rel.node[1] and self.node[1] == rel.node[0]
        return true
      else
        return false
      end
    else
      return false
    end
  end

  # Method eql? is an alias of the === method and is used with hash method
  # to make uniq arry of the Bio::Relation objects.
  #
  #   a1 = Bio::Relation.new('a', 'b', 1)
  #   a2 = Bio::Relation.new('b', 'a', 1)
  #   a3 = Bio::Relation.new('b', 'c', 1)
  # p [ a1, a2, a3 ].uniq
  alias eql? ===

  # Used by the each method to compare with another Bio::Relation object.
  # This method is only usable when the edge objects have the property of
  # the module Comparable.
  def <=>(rel)
    unless self.edge.kind_of? Comparable
      raise "[Error] edges are not comparable"
    end
    if self.edge > rel.edge
      return 1
    elsif self.edge < rel.edge
      return -1
    elsif self.edge == rel.edge
      return 0
    end
  end

end # Relation

end # Bio


#
# = bio/tree.rb - phylogenetic tree data structure class
#
# Copyright::   Copyright (C) 2006
#               Naohisa Goto <ng@bioruby.org>
# License::     The Ruby License
#
#

module Bio

  # This is the class for phylogenetic tree.
  # It stores a phylogenetic tree.
  # 
  # Internally, it is based on Bio::Pathway class.
  # However, users cannot handle Bio::Pathway object directly.
  #
  # This is alpha version. Incompatible changes may be made frequently.
  class Tree

    # Error when there are no path between specified nodes
    class NoPathError < RuntimeError; end

    # Edge object of each node.
    # By default, the object doesn't contain any node information.
    class Edge

      # creates a new edge.
      def initialize(distance = nil)
        if distance.kind_of?(Numeric)
          self.distance = distance
        elsif distance
          self.distance_string = distance
        end
      end

      # evolutionary distance
      attr_reader :distance

      # evolutionary distance represented as a string
      attr_reader :distance_string

      # set evolutionary distance value
      def distance=(num)
        @distance = num
        @distance_string = (num ? num.to_s : num)
      end

      # set evolutionary distance value from a string
      def distance_string=(str)
        if str.to_s.strip.empty?
          @distance = nil
          @distance_string = str
        else
          @distance = str.to_f
          @distance_string = str
        end
      end

      # visualization of this object
      def inspect
        "<Edge distance=#{@distance.inspect}>"
      end

      # string representation of this object
      def to_s
        @distance_string.to_s
      end

      #---
      # methods for NHX (New Hampshire eXtended) and/or PhyloXML
      #+++

      # log likelihood value (:L in NHX)
      attr_accessor :log_likelihood

      # width of the edge
      # (<branch width="w"> of PhyloXML, or :W="w" in NHX)
      attr_accessor :width

      # Other NHX parameters. Returns a Hash.
      # Note that :L and :W
      # are not stored here but stored in the proper attributes in this class.
      # However, if you force to set these parameters in this hash,
      # the parameters in this hash are preferred when generating NHX.
      # In addition, If the same parameters are defined at Node object,
      # the parameters in the node are preferred.
      def nhx_parameters
        @nhx_parameters ||= {}
        @nhx_parameters
      end

    end #class Edge

    # Gets distance value from the given edge.
    # Returns float or any other numeric value or nil.
    def get_edge_distance(edge)
      begin
        dist = edge.distance
      rescue NoMethodError
        dist = edge
      end
      dist
    end

    # Gets distance string from the given edge.
    # Returns a string or nil.
    def get_edge_distance_string(edge)
      begin
        dist = edge.distance_string
      rescue NoMethodError
        dist = (edge ? edge.to_s : nil)
      end
      dist
    end

    # Returns edge1 + edge2
    def get_edge_merged(edge1, edge2)
      dist1 = get_edge_distance(edge1)
      dist2 = get_edge_distance(edge2)
      if dist1 and dist2 then
        Edge.new(dist1 + dist2)
      elsif dist1 then
        Edge.new(dist1)
      elsif dist2 then
        Edge.new(dist2)
      else
        Edge.new
      end
    end

    # Node object.
    class Node

      # Creates a new node.
      def initialize(name = nil)
        @name = name if name
      end

      # name of the node
      attr_accessor :name

      # bootstrap value
      attr_reader :bootstrap

      # bootstrap value as a string
      attr_reader :bootstrap_string

      # sets a bootstrap value
      def bootstrap=(num)
        @bootstrap_string = (num ? num.to_s : num)
        @bootstrap = num
      end

      # sets a bootstrap value from a string
      def bootstrap_string=(str)
        if str.to_s.strip.empty?
          @bootstrap = nil
          @bootstrap_string = str
        else
          i = str.to_i
          f = str.to_f
          @bootstrap = (i == f ? i : f)
          @bootstrap_string = str
        end
      end

      # visualization of this object
      def inspect
        if @name and !@name.empty? then
          str = "(Node:#{@name.inspect}"
        else
          str = sprintf('(Node:%x', (self.__id__ << 1) & 0xffffffff)
        end
        if defined?(@bootstrap) and @bootstrap then
          str += " bootstrap=#{@bootstrap.inspect}"
        end
        str += ")"
        str
      end

      # string representation of this object
      def to_s
        @name.to_s
      end

      # the order of the node
      # (lower value, high priority)
      attr_accessor :order_number

      #---
      # methods for NHX (New Hampshire eXtended) and/or PhyloXML
      #+++

      # Phylogenetic events.
      # Returns an Array of one (or more?) of the following symbols
      #   :gene_duplication
      #   :speciation
      def events
        @events ||= []
        @events
      end

      # EC number (EC_number in PhyloXML, or :E in NHX)
      attr_accessor :ec_number

      # scientific name (scientific_name in PhyloXML, or :S in NHX)
      attr_accessor :scientific_name

      # taxonomy identifier (taxonomy_identifier in PhyloXML, or :T in NHX)
      attr_accessor :taxonomy_id

      # Other NHX parameters. Returns a Hash.
      # Note that :D, :E, :S, and :T
      # are not stored here but stored in the proper attributes in this class.
      # However, if you force to set these parameters in this hash,
      # the parameters in this hash are preferred when generating NHX.
      def nhx_parameters
        @nhx_parameters ||= {}
        @nhx_parameters
      end

    end #class Node

    # Gets node name
    def get_node_name(node)
      begin
        node.name
      rescue NoMethodError
        node.to_s
      end
    end

    def get_node_bootstrap(node)
      begin
        node.bootstrap
      rescue NoMethodError
        nil
      end
    end

    def get_node_bootstrap_string(node)
      begin
        node.bootstrap_string
      rescue NoMethodError
        nil
      end
    end

    # Creates a new phylogenetic tree.
    # When no arguments are given, it creates a new empty tree.
    # When a Tree object is given, it copies the tree.
    # Note that the  new tree shares Node and Edge objects
    # with the given tree.
    def initialize(tree = nil)
      # creates an undirected adjacency list graph
      @pathway = Bio::Pathway.new([], true)
      @root = nil
      @options = {}
      _init_cache
      self.concat(tree) if tree
    end

    # (private) clear internal cache
    def _init_cache
      @cache_parent = {}
    end
    private :_init_cache

    # (private) clear internal cache
    def _clear_cache
      @cache_parent.clear
    end
    private :_clear_cache

    # root node of this tree
    # (even if unrooted tree, it is used by some methods)
    attr_accessor :root

    # tree options; mainly used for tree output
    attr_accessor :options

    # Clears all nodes and edges.
    # Returns self.
    # Note that options and root are also cleared.
    def clear
      initialize
      self
    end

    # Returns all nodes as an array.
    def nodes
      @pathway.graph.keys
    end

    # Number of nodes.
    def number_of_nodes
      @pathway.nodes
    end

    # Iterates over each node of this tree.
    def each_node(&x) #:yields: node
      @pathway.graph.each_key(&x)
      self
    end

    # Iterates over each edges of this tree.
    def each_edge #:yields: source, target, edge
      @pathway.relations.each do |rel|
        yield rel.node[0], rel.node[1], rel.relation
      end
      self
    end

    # Returns all edges an array of [ node0, node1, edge ]
    def edges
      @pathway.relations.collect do |rel|
        [ rel.node[0], rel.node[1], rel.relation ]
      end
    end

    # Returns number of edges in the tree.
    def number_of_edges
      @pathway.relations.size
    end

    # Returns an array of adjacent nodes of the given node.
    def adjacent_nodes(node)
      h = @pathway.graph[node]
      h ? h.keys : []
    end

    # Returns all connected edges with adjacent nodes.
    # Returns an array of the array [ source, target, edge ].
    #
    # The reason why the method name is "out_edges" is that
    # it comes from the Boost Graph Library.
    def out_edges(source)
      h = @pathway.graph[source]
      if h
        h.collect { |key, val| [ source, key, val ] }
      else
        []
      end
    end

    # Iterates over each connected edges of the given node.
    # Returns self.
    #
    # The reason why the method name is "each_out_edge" is that
    # it comes from the Boost Graph Library.
    def each_out_edge(source) #:yields: source, target, edge
      h = @pathway.graph[source]
      h.each { |key, val| yield source, key, val } if h
      self
    end

    # Returns number of edges in the given node.
    #
    # The reason why the method name is "out_degree" is that
    # it comes from the Boost Graph Library.
    def out_degree(source)
      h = @pathway.graph[source]
      h ? h.size : 0
    end

    # Returns an edge from source to target.
    # If source and target are not adjacent nodes, returns nil.
    def get_edge(source, target)
      h = @pathway.graph[source]
      h ? h[target] : nil
    end

    # Adds a new edge to the tree.
    # Returns the newly added edge.
    # If the edge already exists, it is overwritten with new one.
    def add_edge(source, target, edge = Edge.new)
      _clear_cache
      @pathway.append(Bio::Relation.new(source, target, edge))
      edge
    end

    # Finds a node in the tree by given name and returns the node.
    # If the node does not found, returns nil.
    # If multiple nodes with the same name exist,
    # the result would be one of those (unspecified).
    def get_node_by_name(str)
      self.each_node do |node|
        if get_node_name(node) == str
          return node
        end
      end
      nil
    end

    # Adds a node to the tree.
    # Returns self.
    # If the node already exists, it does nothing.
    def add_node(node)
      _clear_cache
      @pathway.graph[node] ||= {}
      self
    end

    # If the node exists, returns true.
    # Otherwise, returns false.
    def include?(node)
      @pathway.graph[node] ? true : false
    end

    # Removes all edges connected with the node.
    # Returns self.
    # If the node does not exist, raises IndexError.
    def clear_node(node)
      unless self.include?(node)
        raise IndexError, 'the node does not exist'
      end
      _clear_cache
      @pathway.relations.delete_if do |rel|
        rel.node.include?(node)
      end
      @pathway.graph[node].each_key do |k|
        @pathway.graph[k].delete(node)
      end
      @pathway.graph[node].clear
      self
    end

    # Removes the given node from the tree.
    # All edges connected with the node are also removed.
    # Returns self.
    # If the node does not exist, raises IndexError.
    def remove_node(node)
      #_clear_cache #done in clear_node(node)
      self.clear_node(node)
      @pathway.graph.delete(node)
      self
    end

    # Removes each node if the block returns not nil.
    # All edges connected with the removed nodes are also removed.
    # Returns self.
    def remove_node_if
      #_clear_cache #done in clear_node(node)
      all = self.nodes
      all.each do |node|
        if yield node then
          self.clear_node(node)
          @pathway.graph.delete(node)
        end
      end
      self
    end

    # Removes an edge between source and target.
    # Returns self.
    # If the edge does not exist, raises IndexError.
    #---
    # If two or more edges exists between source and target,
    # all of them are removed.
    #+++
    def remove_edge(source, target)
      unless self.get_edge(source, target) then
        raise IndexError, 'edge not found'
      end
      _clear_cache
      fwd = [ source, target ]
      rev = [ target, source ]
      @pathway.relations.delete_if do |rel|
        rel.node == fwd or rel.node == rev
      end
      h = @pathway.graph[source]
      h.delete(target) if h
      h = @pathway.graph[target]
      h.delete(source) if h
      self
    end

    # Removes each edge if the block returns not nil.
    # Returns self.
    def remove_edge_if #:yields: source, target, edge
      _clear_cache
      removed_rel = []
      @pathway.relations.delete_if do |rel|
        if yield rel.node[0], rel.node[1], rel.edge then
          removed_rel << rel
          true
        end
      end
      removed_rel.each do |rel|
        source = rel.node[0]
        target = rel.node[1]
        h = @pathway.graph[source]
        h.delete(target) if h
        h = @pathway.graph[target]
        h.delete(source) if h
      end
      self
    end

    # Replaces each node by each block's return value.
    # Returns self.
    def collect_node! #:yields: node
      _clear_cache
      tr = {}
      self.each_node do |node|
        tr[node] = yield node
      end
      # replaces nodes in @pathway.relations
      @pathway.relations.each do |rel|
        rel.node.collect! { |node| tr[node] }
      end
      # re-generates @pathway from relations
      @pathway.to_list
      # adds orphan nodes
      tr.each_value do |newnode|
        @pathway.graph[newnode] ||= {}
      end
      self
    end

    # Replaces each edge by each block's return value.
    # Returns self.
    def collect_edge! #:yields: source, target, edge
      _clear_cache
      @pathway.relations.each do |rel|
        newedge = yield rel.node[0], rel.node[1], rel.relation
        rel.edge = newedge
        @pathway.append(rel, false)
      end
      self
    end

    # Gets the sub-tree consisted of given nodes.
    # _nodes_ must be an array of nodes.
    # Nodes that do not exist in the original tree are ignored.
    # Returns a Tree object.
    # Note that the sub-tree shares Node and Edge objects
    # with the original tree.
    def subtree(nodes)
      nodes = nodes.find_all do |x|
        @pathway.graph[x]
      end
      return self.class.new if nodes.empty?
      # creates subtree
      new_tree = self.class.new
      nodes.each do |x|
        new_tree.add_node(x)
      end
      self.each_edge do |node1, node2, edge|
        if new_tree.include?(node1) and new_tree.include?(node2) then
          new_tree.add_edge(node1, node2, edge)
        end
      end
      return new_tree
    end

    # Gets the sub-tree consisted of given nodes and
    # all internal nodes connected between given nodes.
    # _nodes_ must be an array of nodes.
    # Nodes that do not exist in the original tree are ignored.
    # Returns a Tree object.
    # The result is unspecified for cyclic trees.
    # Note that the sub-tree shares Node and Edge objects
    # with the original tree.
    def subtree_with_all_paths(nodes)
      hash = {}
      nodes.each { |x| hash[x] = true }
      nodes.each_index do |i|
        node1 = nodes[i]
        (0...i).each do |j|
          node2 = nodes[j]
          unless node1 == node2 then
            begin
              path = self.path(node1, node2)
            rescue IndexError, NoPathError
              path = []
            end
            path.each { |x| hash[x] = true }
          end
        end
      end
      self.subtree(hash.keys)
    end

    # Concatenates the other tree.
    # If the same edge exists, the edge in _other_ is used.
    # Returns self.
    # The result is unspecified if _other_ isn't a Tree object.
    # Note that the Node and Edge objects in the _other_ tree are
    # shared in the concatinated tree.
    def concat(other)
      #raise TypeError unless other.kind_of?(self.class)
      _clear_cache
      other.each_node do |node|
        self.add_node(node)
      end
      other.each_edge do |node1, node2, edge|
        self.add_edge(node1, node2, edge)
      end
      self
    end

    # Gets path from node1 to node2.
    # Retruns an array of nodes, including node1 and node2.
    # If node1 and/or node2 do not exist, IndexError is raised.
    # If node1 and node2 are not connected, NoPathError is raised.
    # The result is unspecified for cyclic trees.
    def path(node1, node2)
      raise IndexError, 'node1 not found' unless @pathway.graph[node1]
      raise IndexError, 'node2 not found' unless @pathway.graph[node2]
      return [ node1 ] if node1 == node2
      return [ node1, node2 ] if @pathway.graph[node1][node2]
      _, path = @pathway.bfs_shortest_path(node1, node2)
      unless path[0] == node1 and path[-1] == node2 then
        raise NoPathError, 'node1 and node2 are not connected'
      end
      path
    end

    # Iterates over each edge from node1 to node2.
    # The result is unspecified for cyclic trees.
    def each_edge_in_path(node1, node2)
      path = self.path(node1, node2)
      source = path.shift
      path.each do |target|
        edge = self.get_edge(source, target)
        yield source, target, edge
        source = target
      end
      self
    end

    # Returns distance between node1 and node2.
    # It would raise error if the edges didn't contain distance values.
    # The result is unspecified for cyclic trees.
    def distance(node1, node2)
      distance = 0
      self.each_edge_in_path(node1, node2) do |source, target, edge|
        distance += get_edge_distance(edge)
      end
      distance
    end

    # (private) get parent only by using cache
    def _get_cached_parent(node, root)
      @cache_parent[root] ||= Hash.new
      cache = @cache_parent[root]
      if node == root then
        unless cache.has_key?(root) then
          self.adjacent_nodes(root).each do |n|
            cache[n] ||= root if n != root
          end
          cache[root] = nil
        end
        parent = nil
      else
        unless parent = cache[node] then
          parent = self.adjacent_nodes(node).find { |n|
            (m = cache[n]) && (m != node)
          }
          _cache_parent(node, parent, root) if parent
        end
        parent
      end
    end
    private :_get_cached_parent

    # (private) set parent cache
    def _cache_parent(node, parent, root)
      return unless parent
      cache = @cache_parent[root]
      cache[node] = parent
      self.adjacent_nodes(node).each do |n|
        cache[n] ||= node if n != parent
      end
    end
    private :_cache_parent

    # Gets the parent node of the _node_.
    # If _root_ isn't specified or _root_ is <code>nil</code>, @root is used.
    # Returns an <code>Node</code> object or nil.
    # The result is unspecified for cyclic trees.
    def parent(node, root = nil)
      root ||= @root
      raise IndexError, 'can not get parent for unrooted tree' unless root
      unless ret = _get_cached_parent(node, root) then
        ret = self.path(root, node)[-2]
        _cache_parent(node, ret, root)
      end
      ret
    end

    # Gets the adjacent children nodes of the _node_.
    # If _root_ isn't specified or _root_ is <code>nil</code>, @root is used.
    # Returns an array of <code>Node</code>s.
    # The result is unspecified for cyclic trees.
    def children(node, root = nil)
      root ||= @root
      c = self.adjacent_nodes(node)
      c.delete(self.parent(node, root))
      c
    end

    # Gets all descendent nodes of the _node_.
    # If _root_ isn't specified or _root_ is <code>nil</code>, @root is used.
    # Returns an array of <code>Node</code>s.
    # The result is unspecified for cyclic trees.
    def descendents(node, root = nil)
      root ||= @root
      distance, route = @pathway.breadth_first_search(root)
      d = distance[node]
      result = []
      distance.each do |key, val|
        if val > d then
          x = key
          while x = route[x]
            if x == node then
              result << key
              break
            end
            break if distance[x] <= d
          end
        end
      end
      result
    end

    # If _node_ is nil, returns an array of 
    # all leaves (nodes connected with one edge).
    # Otherwise, gets all descendent leaf nodes of the _node_.
    # If _root_ isn't specified or _root_ is <code>nil</code>, @root is used.
    # Returns an array of <code>Node</code>s.
    # The result is unspecified for cyclic trees.
    def leaves(node = nil, root = nil)
      unless node then
        nodes = []
        self.each_node do |x|
          nodes << x if self.out_degree(x) == 1
        end
        return nodes
      else
        root ||= @root
        self.descendents(node, root).find_all do |x|
          self.adjacent_nodes(x).size == 1
        end
      end
    end

    # Gets all ancestral nodes of the _node_.
    # If _root_ isn't specified or _root_ is <code>nil</code>, @root is used.
    # Returns an array of <code>Node</code>s.
    # The result is unspecified for cyclic trees.
    def ancestors(node, root = nil)
      root ||= @root
      (self.path(root, node) - [ node ]).reverse
    end

    # Gets the lowest common ancestor of the two nodes.
    # If _root_ isn't specified or _root_ is <code>nil</code>, @root is used.
    # Returns a <code>Node</code> object or nil.
    # The result is unspecified for cyclic trees.
    def lowest_common_ancestor(node1, node2, root = nil)
      root ||= @root
      _, route = @pathway.breadth_first_search(root)
      x = node1; r1 = []
      begin; r1 << x; end while x = route[x]
      x = node2; r2 = []
      begin; r2 << x; end while x = route[x]
      return (r1 & r2).first
    end

    # Returns total distance of all edges.
    # It would raise error if some edges didn't contain distance values.
    def total_distance
      distance = 0
      self.each_edge do |source, target, edge|
        distance += get_edge_distance(edge)
      end
      distance
    end

    # Calculates distance matrix of given nodes.
    # If _nodes_ is nil, or is ommited, it acts the same as
    # tree.distance_matrix(tree.leaves).
    # Returns a matrix object.
    # The result is unspecified for cyclic trees.
    # Note 1: The diagonal values of the matrix are 0.
    # Note 2: If the distance cannot be calculated, nil will be set.
    def distance_matrix(nodes = nil)
      nodes ||= self.leaves
      matrix = []
      nodes.each_index do |i|
        row = []
        nodes.each_index do |j|
          if i == j then
            distance = 0
          elsif r = matrix[j] and val = r[i] then
            distance = val
          else
            distance = (self.distance(nodes[i], nodes[j]) rescue nil)
          end
          row << distance
        end
        matrix << row
      end
      Matrix.rows(matrix, false)
    end

    # Shows the adjacency matrix representation of the tree.
    # It shows matrix only for given nodes.
    # If _nodes_ is nil or is ommitted,
    # it acts the same as tree.adjacency_matrix(tree.nodes).
    # If a block is given, for each edge,
    # it yields _source_, _target_, and _edge_, and
    # uses the returned value of the block.
    # Without blocks, it uses edge.
    # Returns a matrix object.
    def adjacency_matrix(nodes = nil,
                         default_value = nil,
                         diagonal_value = nil) #:yields: source, target, edge
      nodes ||= self.nodes
      size = nodes.size
      hash = {}
      nodes.each_with_index { |x, i| hash[x] = i }
      # prepares an matrix
      matrix = Array.new(size, nil)
      matrix.collect! { |x| Array.new(size, default_value) }
      (0...size).each { |i| matrix[i][i] = diagonal_value }
      # fills the matrix from each edge
      self.each_edge do |source, target, edge|
        i_source = hash[source]
        i_target = hash[target]
        if i_source and i_target then
          val = block_given? ? (yield source, target, edge) : edge
          matrix[i_source][i_target] = val
          matrix[i_target][i_source] = val
        end
      end
      Matrix.rows(matrix, false)
    end

    # Removes all nodes that are not branches nor leaves.
    # That is, removes nodes connected with exactly two edges.
    # For each removed node, two adjacent edges are merged and
    # a new edge are created.
    # Returns removed nodes.
    # Note that orphan nodes are still kept unchanged.
    def remove_nonsense_nodes
      _clear_cache
      hash = {}
      self.each_node do |node|
        hash[node] = true if @pathway.graph[node].size == 2
      end
      hash.each_key do |node|
        adjs = @pathway.graph[node].keys
        edges = @pathway.graph[node].values
        new_edge = get_edge_merged(edges[0], edges[1])
        @pathway.graph[adjs[0]].delete(node)
        @pathway.graph[adjs[1]].delete(node)
        @pathway.graph.delete(node)
        @pathway.append(Bio::Relation.new(adjs[0], adjs[1], new_edge))
      end
      #@pathway.to_relations
      @pathway.relations.reject! do |rel|
        hash[rel.node[0]] or hash[rel.node[1]]
      end
      return hash.keys
    end

    # Insert a new node between adjacent nodes node1 and node2.
    # The old edge between node1 and node2 are changed to the edge
    # between new_node and node2.
    # The edge between node1 and new_node is newly created.
    #
    # If new_distance is specified, the distance between
    # node1 and new_node is set to new_distance, and
    # distance between new_node and node2 is set to
    # <code>tree.get_edge(node1, node2).distance - new_distance</code>.
    #
    # Returns self.
    # If node1 and node2 are not adjacent, raises IndexError.
    #
    # If new_node already exists in the tree, the tree would become
    # circular. In addition, if the edge between new_node and
    # node1 (or node2) already exists, it will be erased.
    def insert_node(node1, node2, new_node, new_distance = nil)
      unless edge = self.get_edge(node1, node2) then
        raise IndexError, 'nodes not found or two nodes are not adjacent'
      end
      _clear_cache
      new_edge = Edge.new(new_distance)
      self.remove_edge(node1, node2)
      self.add_edge(node1, new_node, new_edge)
      if new_distance and old_distance = get_edge_distance(edge) then
        old_distance -= new_distance
        begin
          edge.distance = old_distance
        rescue NoMethodError
          edge = old_distance
        end
      end
      self.add_edge(new_node, node2, edge)
      self
    end
  end #class Tree
end #module Bio