/**
 * @file api.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef API_H
#define API_H

#define _POSIX_C_SOURCE 200809L
#include <sys/time.h>

extern char* mysock; //nome del socket a cui connettersi

/**
 * @brief connette al client ad un socket
 * 
 * @param sockname nome del socket
 * @param msec millisecondi tra una richiesta di connessione e l'altra
 * @param abstime tempo massimo per tentare la connessione
 * @return 0 se viene stabilita la connessione, -1 altrimenti. errno viene settata
 */
int openConnection(const char* sockname, int msec, const struct timespec abstime);

// /**
//  * @brief chiude la connessione con il socket
//  * @param sockname nome del socket
//  * @return 0 in caso di successo della chiusura della connessione, -1 altrimenti. errno viene settata
//  */
int closeConnection(const char* sockname);

// /**
//  * @brief richiesta di apertura di un file. Modalità di apertura descritta dai flag che vengono
//  * passati
//  * @param pathname percorso del file
//  * @param flags flags passati alla funzione per creare il file oppure per aprirlo/crearlo
//  * in modalità locked
//  * @return 0 in caso di successo, -1 altrimenti. errno viene settata
//  */
// int openFile(const char* pathname, int flags);


// /**
//  * @brief legge il contenuto del file specificato in pathname
//  * 
//  * @param pathname percorso del file
//  * @param buf buffer allocato sullo heap
//  * @param size dimensione del buffer
//  * @return puntatore all'area di memoria nello heap nel parametro buf.
//  * Restituisce 0 in caso di successo, -1 altrimenti.
//  * errno viene settata a EINVAL per parametri errati,a ENOTCONN se il client non è connesso, a
//  * EBADMSG se il messaggio ricevuto non è valido
//  */
// int readFile(const char* pathname, void** buf, size_t* size);


// /**
//  * @brief richiede la lettura di N file da memorizzare dal server
//  * 
//  * @param N numero di file se N<=0 richiede la lettura di tutti i file nel server
//  * @param dirname cartella dove vengono salvati i file 
//  * @return valore >= 0 in caso di successo, -1 altrimenti. errno viene settata a EINVAL
//  * per parametri errati, ENOTCONN se il client non è connesso, EBADMSG se il messaggio
//  * ricevuto non è valido
//  */
// int readNFiles(int N, const char* dirname);


// /**
//  * @brief scrive il file puntato da pathname nel server
//  * 
//  * @param pathname percorso del file
//  * @param dirname cartella dove vengono inseriti i file vittima se dirname=NULL 
//  * non vengono inseriti in cache 
//  * @return 0 in caso di successo, -1 altrimenti. 
//  * errno viene settata a EINVAL per parametri errati, ENOTCONN se il client non è connesso, EBADMSG se il messaggio
//  * ricevuto non è valido
//  */
// int writeFile(const char* pathname, const char* dirname);


// /**
//  * @brief scrive un buffer in append al file (atomica)
//  * @param pathname percorso del file
//  * @param buf buffer
//  * @param size dimensione del buffer 
//  * @param dirname cartella dove vengono inseriti i file vittima se dirname=NULL 
//  * non vengono inseriti in cache 
//  * 
//  * @return 0 in caso di successo, -1 altrimenti. 
//  * errno viene settata a EINVAL per parametri errati, ENOTCONN se il client non è connesso, EBADMSG se il messaggio
//  * ricevuto non è valido
//  */
// int appendToFile(const char* pathname, void* buf, size_t size, const char* dirname);

// /**
//  * @brief setta il flag O_LOCK al file se l'owner della lock ha richiesto il file
//  * @param pathname percorso del file
//  * @return 0 in caso di successo, -1 altirmenti.
//  * errno viene settata a EINVAL per parametri errati, ENOTCONN se il client non è connesso, EBADMSG se il messaggio
//  * ricevuto non è valido
//  */
// int lockFile(const char* pathname);


// /**
//  * @brief chiude il file
//  * @param pathname percorso del file
//  * @return 0 in caso di successo, -1 altrimenti.
//  * errno viene settata a EINVAL per parametri errati, ENOTCONN se il client non è connesso,
//  * viene settata anche se il file non è aperto
//  */
// int closeFile(const char* pathname);


// /**
//  * @brief rimuove il file dal server
//  * @param pathname percorso del file
//  * @return 0 in caso di successo, -1 altrimenti. Il fallimento accade quando se il file non è locked
//  * o è locked da un processo diverso da chi chiede removeFile
//  */
// int removeFile(const char* pathname);



#endif

