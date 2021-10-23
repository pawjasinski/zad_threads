Standard C++ 14

Zadanie : zaimplementować
: klasa random generator - do generowania liczb pseudolosowych
: kolejka zsynchronizowana
: pula wątków - przy pomocy kolejki zsynchronizowanej

zadanie:
* utwórz 7 wątków
* T1 T2 i T3 będą wątkami-klientami
* T4 i T5 będzie wątkiem serwerem dla klientów
* T6 będzie wątkiem alokującym pamięć dla serwerów
* T7 będzie wątkiem typu watchdog

Wskazówka(można zaimplementować w dowolny, inny sposób)
Muteksy lub semafory :
Jeden wspólny dla T1-5 (klienci dają zadania serwerowi) a drugi wspólny dla T4-6
(serwery dają zadanie dla alokatora pamięci)

Funkcjonalności samej aplikacji:
Klienci:
* Niech wątki klienckie losują liczby z zakresu od 0 do 2147483647 (typ int).
* Niech dokonują losowania około 10x na sekundę (co 100ms).
* Wylosowaną liczbę niech przekazują do serwerów (sposób przekazywania
liczby możesz wybrać sam – możesz to zrobić nawet poprzez globalną tablicę
inny kontener czy strukturę do której przekażesz uchwyt).
* Wylosowane liczby niech klient sobie zapisuje w jakimś kontenerze (w formie
intów) – przyda się to by móc stwierdzić czy wszystkie wylosowane liczby
zostały przetworzone (wypisane) poprawnie przez serwery.
* Przy zamykaniu aplikacji (ctrl+c w terminalu) przechwyć sygnał SIGINT,
zatrzymaj losowanie liczb i przed zamknięciem aplikacji zapisz do plików w
CWD przechowywane liczby w każdym z wątków (osobne 3 pliki).
(najlepiej w formie tekstowej – aby porównanie liczb dla Ciebie i dla nas było
najprostsze).
Serwery:
* Serwer po otrzymaniu liczby powinien przekazać żądanie zaalokowania nowej
pamięci do wątku zajmującego się alokacjami pamięci.
* Po otrzymaniu uchwytu do zaalokowanej pamięci serwer powinien wykonać
operację (zamiana liczby integer na jej tekstową reprezentacje)
itoa(liczba_otrzymana_od_klienta, otrzymany_bufor_z_wątku_alokatora, 10);
* I następnie wypisać na ekran zawartość tego bufora.
Po wypisaniu zawartości bufora - powinien go zwolnić.
* Dodatkowo jeśli serwer otrzyma od wątku-klienta liczbę z zakresu 0-1000
powinien wejść w nieskończoną pętlę po wypisaniu bufora ale przed
zwolnieniem pamięci. Jest to symulowanie np. zgubionego pakietu w
komunikacji asynchronicznej bez potwierdzeń (czekasz na coś bez końca).
Aby nie zamęczyć CPU proponuję:
while(true)
{
usleep(1000);
}
// oczywiście w tej pętli możesz dodać też inny kod który umożliwi interakcję z
wątkiem T7
Z tej sytuacji (prowadzącej do deadlocka i możliwe, że do wycieku pamięci)
wyratować aplikację powinien wątek T7 „watchdog”.Alokator:
* Na żądanie serwera alokuje pamięć np. malloc / calloc / new (sposób
przekazywania uchwytu zaalokowanej pamięci do serwera jest dowolny)
Watchdog:
* Raz na sekundę sprawdza czy wątki pracują, a jeśli zauważy, że któryś wątek
serwerowy w przeciągu sekundy nie wykonał żadnego nowego zadania to
wdroży ”jakąś” (tutaj wybór należy do Ciebie) operację która przywróci,
zablokowany wątek serwerowy do życia.