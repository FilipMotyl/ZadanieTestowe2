# ZadanieTestowe2

Developed with Unreal Engine 4
Developer Unreal Engine/C++

Zadanie rekrutacyjne
Czas na wykonanie: 3 dni (od dnia otrzymania maila)
Każde zadanie zostanie sprawdzone pod względem ukończenia, rozwiązań i jakości
kodu. Prosimy o przesyłanie linków do repozytoriów z projektem lub całego projektu
na dysku do pobrania (z odpowiednimi uprawnieniami udostępniania).
Wytyczne:
- Wersja silnika Unreal Engine 4.27
- Programowanie w C++ (dozwolone użycie Blueprint’ów tylko zadaniu 4.)
- Użycie “Third person template” jako bazy
Cel zadania

Stwórz prostą grę pozwalającą na poruszanie się postacią pod ‘WSAD’ oraz Player
Controller implementujący rzut piłką pod prawy przyciskiem myszy oraz interakcję z
przedmiotami pod klawiszem ‘E’.

Zadanie 1.
- Stwórz postać z widokiem z trzeciej osoby, poruszającą się pod WSAD.
(zaimplementowaną w C++)
Zadanie 2.
- Stwórz prostą skrzynie z która gracz będzie mógł wejść w interakcję pod
klawiszem ‘E’ (mile widziany indykator interakcji (UI, outline, zmiana koloru))
- Skrzynia musi mieć 2 stany otwarta / zamknięta
- Po każdym otwarciu skrzyni musi wypaść z niej piłka

Zadanie 3.
- Gracz musi mieć możliwość podniesienia piłki (pod przyciskiem ‘E’) oraz jej
rzucenia klikając prawy przycisk myszy
- Piłka musi snapować się do ręki postaci
- Należy stworzyć UI informujące o stanie posiadanych piłek np: napis “Ball: 1
lub 0” w zależności czy gracz ma piłkę czy nie

Zadanie 4. (dozwolone użycie Blueprintów - Niagara)
- Stworzyć efekt wizualny, który będzie pokazywał trajektorie lotu piłki

Zadanie 5.
- Stwórz AI (Postać i controller), która po rzucie przez gracza piłki, pobiegnie do
niej, podniesie ją, oraz przyniesie do gracza. Po wykonanym zadaniu AI musi
upuścić piłke i zniknąć
Zalecane użycie behaviour tree.
