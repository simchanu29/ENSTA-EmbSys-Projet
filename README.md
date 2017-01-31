# ENSTA-EmbSys-Projet
##### Projet de système embarqué à l'ENSTA Bretagne

## Sommaire

__1.__ [Installation](#installation)  

__2.__ [Utilisation](#utilisation)  

__3.__ [Informations annexes](#informations-annexes)  

___

## __1.__ Utilisation<a name="utilisation" />

__1.__ Connecter l'ordinateur avec un switch à la raspberry  
__2.__ Lancer `main-client.out adresse message` sur le PC pour envoyer le message voulu

___

## __2.__ Installation<a name="installation" />

### Installation de l'OS à partir de Windows
__1.__ Télécharger la dernière version de Raspbian (version sans interface graphique) à partir du site de Raspberry.  
__2.__ Utiliser Win32DiskImager pour écrire l'image disque sur une la carte SD de la Raspberry  
__3.__ Démonter la carte SD du PC et l'insérer dans la Raspberry Pi

### Configuration du proxy
Voir le share de Lebars, en particulier les exports et les acquire pour la configuration par ethernet pour l'ENSTA Bretagne.
```
http://www.ensta-bretagne.fr/lebars/Share/Ubuntu.txt
```
Dans le cas d'une utilisation du wifi modifier ou créer `wpa_supplicant.conf` dans `/etc/wpa-supplicant/` 
```
network={
        ssid="your_ssid"
        psk="your_passwd"
}
```
Puis on reboot la connection wifi : 
```
sudo ifdown wlan0
sudo ifup wlan0
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
cd ENSTA-EmbSys-Projet
git submodules init
git submodules update
```

### Mise en place d'une adresse ip statique
On utilise le tutoriel suivant :  
http://www.framboise314.fr/allouer-une-adresse-ip-fixe-au-raspberry/  

Dans notre cas nous avons alloués l'adresse ip `192.168.1.20`

Il faut aussi allouer une adresse ip statique au PC qui indique quee les deux appareils sont sur le même réseau. 
Dans notre cas nous utilisons `192.168.1.21`

### Compilation

#### Compilation avec cmake sur la raspberry

Pour compiler les fichier, creer un répertoire de compilation, 
par exemple cmake-build-debug, se placer dans ce dossier
et lancer les commandes:
cmake ..
make

Cela va permettre de générer les fichiers intermédiaire dans le dossier cmake-build-debug.
Les executables seront générés dans un dossier build.

On peut executer les executables. 
Il faut lancer les serveur dans un terminal, puis le client dans un autre,
avec les commandes:
./server.out
./client.out localhost "le message..."

On peut modifier le port utilisé qui est ici 51717, il faut seulement que le port soit libre
localhost est utilisé lorsque le serveur tourne sur la même machine que le client

#### cross-compilation avec cmake 

___

## __3.__ Informations annexes<a name="informations-annexes" />

#### Cross compilation
On utilise les tutoriels suivants :  
https://solderspot.wordpress.com/2014/11/17/cross-compiling-for-raspberry-pi-part-i/  
https://solderspot.wordpress.com/2014/11/17/cross-compiling-for-raspberry-pi-part-ii/  

Ces tutoriels utilisent une version précompilée de la toolchain, par conséquent aucune compilation n'est nécessaire.

#### Générer la documentation
Pour générer la documentation il faut utiliser doxygen.  
```
sudo apt-get install doxygen
```
Puis de le lancer avec le fichier de configuration à la racine du projet
```
doxygen dConfig.doxygen
```

#### Troubleshooting
 - Le code contiens des parties valides uniquement sous C++11, par conséquent il faut g++ 4.6 ou plus lors de la compilation
