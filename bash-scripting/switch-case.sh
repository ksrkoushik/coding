#!/bin/bash
read -p "Enter the name of your car brand: " car
case $car in
Tesla)
echo "${car}'s car factory is in the USA."
;;
BMW | Mercedes | Audi | Porsche)
echo "${car}'s car factory is in Germany."
;;
Toyota | Mazda | Mitsubishi | Subaru)
echo "${car}'s car factory is in Japan."
;;
*)
echo "${car} is an unknown car brand"
;;
esac
