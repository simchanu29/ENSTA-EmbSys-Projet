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

___

## Installation de la raspberry
### Configuration du proxy
voir le share de Lebars en particulier les exports et les acquire pour la configuration par ethernet pour l'ecole
Dans le cas du wifi modifier wpa_supplicant.conf 
```
network={
        ssid="your_ssid"
        psk="your_passwd"
}
```

### Mise a jour  
```
sudo apt-get update  
sudo apt-get upgrade
sudo apt-get install git 
```
Pour cloner le code il suffit de faire : 
```
git clone https://github.com/simchanu29/ENSTA-EmbSys-Projet.git
```
## Cross compilation
On utilise les tutoriels suivants :  
https://solderspot.wordpress.com/2014/11/17/cross-compiling-for-raspberry-pi-part-i/  
https://solderspot.wordpress.com/2014/11/17/cross-compiling-for-raspberry-pi-part-ii/  

Ces tutoriels utilisent une version précompilée de la toolchain, par conséquent aucune compilation n'est nécessaire.
