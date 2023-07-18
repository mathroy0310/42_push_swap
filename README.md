# Push_swap

Ce document est le fichier README pour le projet Push_swap de l'école 42. Push_swap est un projet qui consiste à trier une pile d'entiers en utilisant un ensemble limité d'opérations. Le but du projet est de développer deux programmes : `push_swap` et `checker`.

## Introduction

Le projet Push_swap est un exercice de tri algorithmique. L'objectif principal est de trier une pile d'entiers dans un ordre croissant en utilisant deux piles supplémentaires et un ensemble limité d'opérations. Le programme `push_swap` doit générer une liste d'opérations permettant de trier la pile, tandis que le programme `checker` vérifie si la liste d'opérations fournie est valide et trie effectivement la pile.

## Installation

Pour utiliser ce projet, suivez les étapes suivantes :

1. Clonez ce dépôt sur votre machine locale.
2. Assurez-vous que vous avez le compilateur C installé sur votre système.
3. Exécutez `make` à la racine du projet pour compiler le programme `push_swap`.

## Utilisation

### push_swap

Pour utiliser le programme `push_swap`, exécutez la commande suivante :

```
./push_swap [liste d'entiers]
```

Remplacez `[liste d'entiers]` par la liste d'entiers que vous souhaitez trier. Par exemple :

```
./push_swap 3 1 2
```

Le programme affichera ensuite la liste des opérations nécessaires pour trier la pile.

### Exemples

Voici quelques exemples d'utilisation des programmes `push_swap` et `checker` :

```bash
$ ./push_swap 3 1 2
sa
rra
```

## Ressources

- [Documentation de l'école 42]([https://cdn.intra.42.fr/pdf/pdf/93074/fr.subject.pdf])
- 
## Auteur

Ce projet a été développé par Mathieu Roy (maroy) dans le cadre du cursus de l'école 42.
