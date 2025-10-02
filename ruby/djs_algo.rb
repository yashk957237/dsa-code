require 'set'

def dijkstra(graph, start)
  distances = Hash.new(Float::INFINITY)
  distances[start] = 0

  visited = Set.new
  queue = Set.new([start])

  until queue.empty?
    current = queue.min_by { |node| distances[node] }
    queue.delete(current)
    visited.add(current)

    graph[current]&.each do |neighbor, weight|
      next if visited.include?(neighbor)
      alt = distances[current] + weight
      if alt < distances[neighbor]
        distances[neighbor] = alt
        queue.add(neighbor)
      end
    end
  end

  distances
end