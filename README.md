# ENSTA-EmbSys-Projet
Projet de système embarqué à l'ENSTA Bretagne

Pour compiler les fichier, creer un répertoire de compilation, 
par exemple cmake-build-debug, se placer dans ce dossier
et lancer les commandes:
cmake ..
make

Cela va permettre de générer les fichiers intermédiaire dans le dossier cmake-build-debug.
Les executables seront générés dans un dossier build.

On peut executer les executables. Pour le client serveur, 
il faut lancer les serveur dans un terminal, puis le client dans un autre,
avec les commandes:
./server.out 51717
./client.out localhost 51717 "le message..."

Le fichier unitest joue le role de serveur et produit le morse
./unitest.out 51717
./client.out localhost 51717 "le message..."


On peut modifier le port qui est ici 51717, il faut seulement que le port soit libre
localhost est utilisé lorsque le serveur tourne sur la même machine que le client


## Installation de la raspberry
### Configuration du proxy
voir le share de Lebars en particulier les exports et les acquire  
Dans le cas du wifi modifier wpa_supplicant.conf  
```
network={
        ssid=""
        psk=""
        }
        ```
