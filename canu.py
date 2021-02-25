from fistine import *

def IdealTimeCars(D, N, M, nbCars, bonusPoint, real_streets, paths, streets_name):
  "Durée Trajets idéal de chaque voiture"
  IdealTimes = []
  for i in range(nbCars):
    duration = 0
    for j in path:
      duration += streets_name[2]
    IdealTimes.append(duration)
  return IdealTimes



