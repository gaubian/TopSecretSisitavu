
#D, N, M, nbCars, bonusPoint, real_streets, paths = 6, 4, 5, 2, 1000, [(2, 0, 'rue-de-londres', 1), (0, 1, 'rue-d-amsterdam', 1), (3, 1, 'rue-d-athenes', 1), (2, 3, 'rue-de-rome', 2), (1, 2, 'rue-de-moscou', 3)], [['rue-de-londres', 'rue-d-amsterdam', 'rue-de-moscou', 'rue-de-rome'], ['rue-d-athenes', 'rue-de-moscou', 'rue-de-londres']]

def streetNames(D, N, M, nbCars, bonusPoint, real_streets, paths):
  streets_name = {}
  for i in range(M):
    streets_name[real_streets[i][2]] = [real_streets[i][0], real_streets[i][1], real_streets[i][3]]
  return streets_name

""" streets_name = streetNames(D, N, M, nbCars, bonusPoint, real_streets, paths)
print(streets_name) """

def IdealTimeCars(D, N, M, nbCars, bonusPoint, real_streets, paths, streets_name):
  "Durée Trajets idéal de chaque voiture"
  IdealTimes = []
  for i in range(nbCars):
    for path in paths:
      duration = 0
      for j in path:
        duration += streets_name[j][2]
      if duration <= D:
        score = bonusPoint + (D - duration)
      else:
        score = 0
      IdealTimes.append((duration, score))
  return IdealTimes

""" print(IdealTimeCars(D, N, M, nbCars, bonusPoint, real_streets, paths, streets_name)) """
