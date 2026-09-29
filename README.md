# Passerelle Modbus TCP/IP ↔ Modbus RTU

> Projet BUT GEII 2023–2024 réalisé en binôme : supervision et contrôle à distance d'un régulateur **Eurotherm 2216e**.  
> **English version below.**

## 🇫🇷 Vue d'ensemble

Deux applications C++ Builder communiquent à travers le réseau de l'IUT. Le poste serveur joue aussi le rôle de passerelle vers le régulateur connecté en série.

```text
Application client / IHM
        │
   sockets TCP/IP
        │
        ▼
Serveur C++ Builder / passerelle
        │
   trames Modbus RTU
   + CRC16
        │
      RS-232
        │
        ▼
Eurotherm 2216e
```

Le client affiche la température et la consigne, trace leur évolution et permet d'envoyer une nouvelle consigne. La passerelle traduit ces demandes en échanges Modbus RTU avec le régulateur.

## Chaîne de communication

### Client ↔ passerelle

Les deux applications utilisent une architecture client/serveur TCP/IP. Le client initie les échanges et interroge périodiquement le serveur. Les documents archivés montrent une alternance entre les demandes de température et de consigne, avec mise à jour de l'IHM et du graphique.

### Passerelle ↔ régulateur

La liaison terrain utilise **RS-232 + Modbus RTU** via le composant TComPort.

Le serveur :
1. construit la requête Modbus ;
2. ajoute le **CRC16** calculé dynamiquement ;
3. transmet la trame sur le port série ;
4. récupère la réponse dans le callback de réception ;
5. reconstruit la valeur à partir des octets reçus et applique le facteur d'échelle ;
6. rend la valeur disponible au client TCP.

Les essais ont été réalisés avec **ModbusDoctor** et HyperTerminal avant l'intégration complète.

## Opérations Modbus vérifiées dans le rapport

- fonction **03** pour la lecture de registres ;
- fonction **06** pour l'écriture d'un registre ;
- lecture de la température et de la consigne ;
- écriture de la consigne ;
- calcul et ajout du CRC16.

Le rapport indique que la consigne est associée au registre 2 du régulateur utilisé pendant le projet.

## IHM client

L'application client comporte notamment :
- connexion/déconnexion au serveur ;
- affichage de la température ;
- affichage de la consigne ;
- saisie d'une nouvelle consigne ;
- validation de la saisie numérique ;
- graphique température/consigne en fonction du temps.

## Gestion de la réception série

Un point rencontré pendant l'intégration était la réception d'une réponse série en plusieurs événements. Le programme conservait les octets reçus dans un buffer et utilisait un indicateur pour distinguer les événements de réception.

Pour une écriture de consigne, l'interrogation périodique était temporairement suspendue pendant l'échange, puis relancée après l'opération.

## Résultat et limite identifiée

Le rapport final valide :
- les échanges client/serveur ;
- l'acquisition réelle de température ;
- la communication régulateur ↔ passerelle ;
- l'affichage côté client ;
- la modification distante de la consigne.

L'amélioration principale identifiée concernait la **gestion robuste des erreurs côté serveur**, notamment si le régulateur n'était pas alimenté ou si la liaison série était indisponible.

## Technologies

**C++ · C++ Builder · TCP/IP · sockets · Modbus RTU · RS-232 · CRC16 · TComPort · ModbusDoctor · Eurotherm 2216e**

## Robotique industrielle associée

Des travaux complémentaires sur robots **Stäubli/VAL3** et sur une cellule **Fanuc–Stäubli–Siemens–Keyence** sont documentés dans [`docs/industrial-robotics.md`](docs/industrial-robotics.md). Ils sont séparés du projet Modbus pour ne pas mélanger les périmètres.

## Sources du dépôt

Les rapports et présentations permettent de documenter précisément l'architecture et le comportement, mais les fichiers `.cpp/.h` originaux n'ont pas été retrouvés dans l'archive. Aucun code n'est donc reconstruit artificiellement.

---

# 🇬🇧 Modbus TCP/IP ↔ Modbus RTU Gateway

Two C++ Builder applications were developed for remote monitoring and control of an **Eurotherm 2216e** temperature controller.

The client communicates with a gateway/server through TCP/IP sockets. The gateway builds Modbus RTU requests, appends a CRC16 and exchanges frames with the controller over RS-232.

Verified project features include Modbus function 03 register reads, function 06 register writes, temperature and setpoint acquisition, remote setpoint updates and a client GUI with real-time plotting.

The final report confirms end-to-end communication and identifies server-side error handling for unavailable serial hardware as the main remaining robustness improvement.

**Stack:** C++ · C++ Builder · TCP/IP · Modbus RTU · RS-232 · CRC16 · TComPort

The original C++ source files are no longer present in the archive, so this repository documents the verified implementation without fabricating replacement code.
