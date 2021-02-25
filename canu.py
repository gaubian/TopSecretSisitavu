from fistine import *

def streetNames(D, N, M, nbCars, bonusPoint, real_streets, paths):
  streets_name = {}
  for i in range(M):
    streets_name[real_streets[2]] = [real_streets[0], real_streets[1], real_streets[3]]
  return streets_name

def IdealTimeCars(D, N, M, nbCars, bonusPoint, real_streets, paths, streets_name):
  "Durée Trajets idéal de chaque voiture"
  IdealTimes = []
  for i in range(nbCars):
    duration = 0
    for j in path:
      duration += streets_name[j][2]
    IdealTimes.append((duration, bonusPoint + (D - duration))
  return IdealTimes



