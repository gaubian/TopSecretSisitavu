
D, N, M, nbCars, bonusPoint, real_streets, paths = 6, 4, 5, 2, 1000, [(2, 0, 'rue-de-londres', 1), (0, 1, 'rue-d-amsterdam', 1), (3, 1, 'rue-d-athenes', 1), (2, 3, 'rue-de-rome', 2), (1, 2, 'rue-de-moscou', 3)], [['rue-de-londres', 'rue-d-amsterdam', 'rue-de-moscou', 'rue-de-rome'], ['rue-d-athenes', 'rue-de-moscou', 'rue-de-londres']]

def streetNames(D, N, M, nbCars, bonusPoint, real_streets, paths):
  streets_name = {}
  for i in range(M):
    streets_name[real_streets[i][2]] = [real_streets[i][0], real_streets[i][1], real_streets[i][3]]
  return streets_name

streets_name = streetNames(D, N, M, nbCars, bonusPoint, real_streets, paths)

def idealTimeCars(D, N, M, nbCars, bonusPoint, real_streets, paths, streets_name):
  "Durée Trajets idéal de chaque voiture"
  IdealTimes = []
  for i, path in enumerate(paths):
    duration = 0
    for j in path[1:]:
      duration += streets_name[j][2]
    if duration <= D:
      score = bonusPoint + (D - duration)
    else:
      score = 0
    IdealTimes.append((i, duration, score))
  IdealTimes.sort(key=lambda x : -x[2])
  return IdealTimes

def idealScore(ideal_times):
  summed = 0
  for _, _, score in ideal_times:
    summed += score
  return summed


ideal_times = idealTimeCars(D, N, M, nbCars, bonusPoint, real_streets, paths, streets_name)
print(ideal_times)
print(idealScore(ideal_times))

def visitedStreets(M, nbList, cars_list, streets_name, paths):
  visited_streets = {}
  for car in cars_list:
    for street in paths[car[0]][1:]:
      visited_streets[street] = visited_streets.get(street, 0) + 1
  return visited_streets

print(visitedStreets(M, nbCars, ideal_times, streets_name, paths))

