# minitalk because

fonction documentation :

- [ ] signal
- [ ] sigemptyset
- [ ] sigaddset
- [ ] sigactoin
- [ ] kill
- [ ] getpid
- [ ] pause
- [ ] sleep
- [ ] usleep

fonctionnement du client :
	premier bit envoyer : le bit de queue il a besoin d'une confirmation pour avancer;
	une premier chaine de caractaire est creer pour envoyer la tail de la string pour faire un seul malloc sur ca
	apre vasy c'est la vrai string qui est envoyer;

fonctionnement du server :
	a chaque nouveau client il vas l'ajouter a la queue;
	une fois tout les operation fini avec le client actuel, il vas passer au suivent;
	une fois sur un nouveau client il envoie juste une reponse;
	dans le cas ou un client ne repond pas il vas juste le jarter;
