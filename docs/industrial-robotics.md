# Robotique industrielle — travaux complémentaires

Ce document regroupe des travaux GEII complémentaires qui apportent du contexte au projet principal de communication industrielle sans les présenter comme faisant partie de la passerelle Eurotherm.

## Stäubli / VAL3

Des séances de robotique ont porté sur la programmation d'un robot Stäubli en **VAL3** pour manipuler des Kaplas.

Éléments travaillés :
- points articulaires et cartésiens ;
- repères outil et repères de travail ;
- mouvements rapides/lents et approches linéaires ;
- lissage des trajectoires avec Blend ;
- pilotage d'une pince ;
- calcul de positions intermédiaires à partir de points de référence ;
- IHM opérateur avec autorisation de prise ;
- recalage d'un repère lorsque la caisse change de position.

Une étape suivante a structuré plusieurs fonctions sous forme de bibliothèque pour la gestion d'une palette 2D, d'une tour et des outils.

## Cellule Fanuc / Stäubli / Siemens / Keyence

Un projet industriel réalisé en binôme a ensuite travaillé sur une cellule comportant :
- robot **Fanuc** ;
- robot Stäubli ;
- automate Siemens / TIA Portal ;
- convoyeur ;
- caméras Keyence ;
- zones de prise/dépose partagées.

Le programme Fanuc utilise des positions d'approche, des sorties pour l'aspiration et une boucle de prise/dépose. La coordination des deux robots passe par une **réservation de zone** échangée avec l'automate afin d'éviter les conflits.

Une logique de priorité a également été ajoutée pour choisir entre une prise en zone de stockage et un objet détecté sur le convoyeur.

Les difficultés consignées dans la présentation concernent notamment les délais réseau, la détection caméra et le recalage/placement de la vision.

## Pourquoi ce contenu n'est pas publié comme code source

Les archives disponibles mélangent programmes existants de la cellule, ressources pédagogiques et modifications réalisées pendant les projets. Sans historique permettant d'attribuer proprement chaque fichier, je préfère documenter les éléments vérifiés plutôt que republier du code dont la propriété exacte serait ambiguë.
