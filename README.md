# Passerelle Modbus TCP/IP ↔ Modbus RTU

> Projet universitaire de communication industrielle réalisé en BUT GEII.  
> **English version available below.**

## 🇫🇷 Présentation

Ce projet avait pour objectif de concevoir une **passerelle de communication entre un client réseau et un régulateur de température Eurotherm 2216e**.

Le système repose sur un ordinateur jouant le rôle de passerelle :
- côté réseau, une application **client communique avec un serveur en TCP/IP** ;
- côté terrain, le serveur échange avec le régulateur via une **liaison série RS-232 utilisant Modbus RTU**.

L'objectif final était de permettre la **surveillance à distance de la température**, son affichage graphique et la modification de la consigne depuis un poste du réseau.

## Architecture

```text
┌─────────────────┐       TCP/IP        ┌────────────────────┐
│ Application     │ <-----------------> │ Application serveur│
│ client / IHM    │                     │ / passerelle       │
└─────────────────┘                     └─────────┬──────────┘
                                                 │ RS-232
                                                 │ Modbus RTU
                                       ┌─────────▼──────────┐
                                       │ Eurotherm 2216e   │
                                       │ Régulateur        │
                                       └────────────────────┘
```

## Fonctionnalités réalisées

- développement de deux applications : **client et serveur** ;
- connexion et échanges par **sockets TCP/IP** ;
- communication série **RS-232** ;
- construction et lecture de trames **Modbus RTU** ;
- calcul du **CRC16 Modbus** ;
- lecture de la température mesurée ;
- transmission de la valeur au client ;
- interface graphique de supervision ;
- affichage de l'évolution de la température sous forme de courbe ;
- travail sur l'écriture d'une nouvelle consigne de température.

## Technologies et matériel

**Développement :** C++, C++ Builder, Windows  
**Réseau :** TCP/IP, sockets client/serveur  
**Industriel :** Modbus RTU, RS-232, CRC16  
**Outils :** ModbusDoctor, HyperTerminal, TComPort  
**Matériel :** régulateur de température Eurotherm 2216e

## Ce que ce projet m'a apporté

Ce projet m'a permis de travailler sur toute une chaîne de communication, de l'interface utilisateur jusqu'à un équipement industriel. Il combine programmation C++, réseau, protocole industriel, communication série et intégration matériel/logiciel.

## Contenu du dépôt

Les sources C++ originales n'étant plus disponibles dans mes archives, ce dépôt sert de **documentation technique et de portfolio du projet**. Il ne contient donc pas de reconstitution artificielle du code original.

---

# 🇬🇧 Modbus TCP/IP ↔ Modbus RTU Gateway

## Overview

University project completed during my BUT GEII studies. The goal was to build a **communication gateway between a network client and an Eurotherm 2216e temperature controller**.

A computer acted as the gateway:
- a client application communicated with the server through **TCP/IP sockets**;
- the server communicated with the industrial controller through **RS-232 using Modbus RTU**.

The system was designed for remote temperature monitoring, graphical visualization and remote setpoint control.

## Architecture

```text
┌─────────────────┐       TCP/IP        ┌────────────────────┐
│ Client          │ <-----------------> │ Gateway / server   │
│ application     │                     │ application        │
└─────────────────┘                     └─────────┬──────────┘
                                                 │ RS-232
                                                 │ Modbus RTU
                                       ┌─────────▼──────────┐
                                       │ Eurotherm 2216e   │
                                       │ Controller        │
                                       └────────────────────┘
```

## Implemented features

- client and server applications;
- TCP/IP socket communication;
- RS-232 serial communication;
- Modbus RTU frame generation and parsing;
- Modbus CRC16 calculation;
- temperature acquisition;
- data forwarding to the network client;
- supervision GUI;
- temperature graph visualization;
- work on remote temperature setpoint writing.

## Technologies

**Development:** C++, C++ Builder, Windows  
**Networking:** TCP/IP, client/server sockets  
**Industrial communication:** Modbus RTU, RS-232, CRC16  
**Tools:** ModbusDoctor, HyperTerminal, TComPort  
**Hardware:** Eurotherm 2216e temperature controller

## Repository note

The original C++ source files are no longer present in my archived project files. This repository therefore documents the engineering work without pretending to reconstruct the original implementation.
