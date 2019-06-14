# REFACTORING EN C++
Ce repository a été créé dans le but d'effectuer le laboratoire 5 du cours GEN 2019 de la HEIG-VD. Son but est de pratiquer le refactoring, les tests unitaires et les mocks en C++. 

## Auteurs
- Bouyiatiotis Stéphane -> scout407
- Gomes da Costa Joshua -> joshuaGomesDaCosta
- Savary Alison -> Boosterloop

## Donnée
Le but de ce laboratoire est de refactorer le code C++ fournit étape par étape. Pour cela, vous devrez
- Créer un projet C++ avec CLion (et donc CMake) et le mettre sur GitHub
- Ajouter GoogleTest à ce projet pour vous permettre d'y ajouter des tests unitaires. Utilisez par exemple https://github.com/Crascit/DownloadProject
- Ecrire un test d'intégration pour la méthode statement() de la classe Customer.
- Voir https://github.com/google/googletest/blob/master/googletest/docs/primer.md 
- Refactorer le code pas à pas en commitant après chaque changement passant les tests. 
- Au fur et à mesure que vous refactorez le code, écrire des tests unitaires pour les méthodes extraites qui effectuent un calcul. A la fin du refactoring, vos test unitaires doivent être réellement unitaires, i.e. ne tester qu'une seule classe à la fois, en mockant si nécessaire les appels à d'autres classes avec googlemock.
- Voir https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md
- Après refactoring, il devrait être facile d'ajouter une fonction statementMarkDown() qui crée un statement similaire au format markdown. Il devrait aussi être facile d'ajouter d'autres types de codes de prix (en utilisant le polymorphisme). Mais vous ne devez pas faire ces ajouts, juste les préparer en refactorant le code dans ce sens. 
