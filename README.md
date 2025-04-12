# Projet en cours ♻️

## Description 
- Trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles.
- Page 15/15 done

### Keywords
- Notions de pile et éléments de manipulation
- Complexité (le + vite possible)

### Algorithme de tri choisi 
- Tri radix car tri par insertion a optimiser.

### Structure choisie pour la pile
- Liste chaînée plutôt que tableau avec buffer pour la scalabilité. Liste chaînée simple car pas vu utilité liste circulaire ou doublement chaînée. 

## To test
- [ ] 80% : trier 100 nombres aléatoires en moins de 700 opérations (moyenne, mais vous devriez toujours avoir au max moins de 700 opérations pour effectuer le tri complet) -> cas ou tri plus long ?
- [ ] 100% : trier 500 nombres aléatoires en un maximum de 5500 opérations
- [ ] norminette : structures dans un autre .h ?
- [ ] x segmentation fault x bus error x double free, ds cas limites definis 
- [ ] franci/checker
- [ ] make fclean, enlever checker -> file names/git repo
- [ ] (guidelines -> main/tests : 3 exemples subject)
- [ ] cas "1 2 " " 2 3" ./push_swap "1 2 4 3" 76 90 "348 05 -> choice
- [ ] cas 1 seul nb
