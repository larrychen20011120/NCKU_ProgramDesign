#include <stdio.h>
#include <stdbool.h>
#define SUIT 4
#define RANK 13

bool min_straight;
int analyze_cards(const int *num_r, const int *num_s, const char *rank, const char *suit);
bool straight(const int*, const int*);
bool flush(const int*, const int*);
bool four_of_a_kind(const int*, const int*);
bool fullhouse(const int*, const int*);
bool three_of_a_kind(const int*, const int*);
bool two_pairs(const int*, const int*);
bool pair(const int*, const int*);

int main() {
    char suit[5], rank[5], person[4] = {'A', 'B', 'C', 'D'};
    int person_value[4];
    for (int j = 0; j < 4; j++) {
        int num_in_rank[RANK] = {0}, num_in_suit[SUIT] = {0};
        for (int i = 0; i < 5; i++) {
            rank[i] = getchar();
            suit[i] = getchar();
            // ignore the space
            getchar();
            if (rank[i] >= '2' && rank[i] <= '9') {
                rank[i] -= '2';
            } else if (rank[i] == 'a') {
                rank[i] = 12;
            } else if (rank[i] == 'k') {
                rank[i] = 11;
            } else if (rank[i] == 'q') {
                rank[i] = 10;
            } else if (rank[i] == 'j') {
                rank[i] = 9;
            } else {
                rank[i] = 8;
            }
            switch (suit[i]) {
                case 's':
                    suit[i] = 3;
                    break;
                case 'h':
                    suit[i] = 2;
                    break;
                case 'd':
                    suit[i] = 1;
                    break;
                default:
                    suit[i] = 0;
            }
            num_in_rank[rank[i]]++;
            num_in_suit[suit[i]]++;
        }
        person_value[j] = analyze_cards(num_in_rank, num_in_suit, rank, suit);
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3 - i; j++){
            if (person_value[j] < person_value[j + 1]){
                int temp_value = person_value[j];
                person_value[j] = person_value[j + 1];
                person_value[j + 1] = temp_value;
                char temp;
                temp = person[j];
                person[j] = person[j + 1];
                person[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 4; i++)
        printf("%c ", person[i]);
    return 0;
}
/*************************************************
 *
 *  straight flush (both a straight and a flush) : 9
 *
 *  four-of-a-kind (four cards of the same rank) : 8
 *
 *  full house (a three-of-a-kind and a pair) : 7
 *
 *  flush (five cards of the same suit) : 6
 *
 *  straight (five cards with consecutive ranks) : 5
 *
 *  three-of-a-kind (three cards of the same rank) : 4
 *
 *  two pairs : 3
 *
 *  pair (two cards of the same rank) : 2
 *
 *  high card (any other hand) : 1
 ******************************************************/

int analyze_cards(const int *num_r, const int *num_s, const char *rank, const char *suit){
    int card_value = 0;
    if (straight(num_r, num_s) && flush(num_r, num_s)) {
        card_value += 9000;
        for (int i = RANK - 1; i >= 0; i--){
            if (*(num_r + i) != 0){
                card_value = card_value + i * 10;
                break;
            }
        }
        for (int i = SUIT - 1; i >= 0; i--){
            if (*(num_s + i) != 0){
                card_value = card_value + i;
                break;
            }
        }
    }
    else if (flush(num_r, num_s)) {
        card_value += 6000;
        for (int i = RANK - 1; i >= 0; i--){
            if (*(num_r + i) != 0){
                card_value = card_value + i * 10;
                break;
            }
        }
        for (int i = SUIT - 1; i >= 0; i--){
            if (*(num_s + i) != 0){
                card_value = card_value + i;
                break;
            }
        }
    }
    else if (straight(num_r, num_s)){
        card_value += 5000;
        if (min_straight){
            for (int i = 0; i < 5; i++){
                if (rank[i] == 12)
                    card_value += suit[i];
            }
        }
        else {
            int object_r;
            for (int i = RANK - 1; i >= 0; i--) {
                if (*(num_r + i) != 0) {
                    card_value = card_value + (i + 1) * 10;
                    object_r = i;
                    break;
                }
            }
            int max_suit = -1;
            for (int i = 0; i < 5; i++) {
                if (*(rank + i) == object_r) {
                    max_suit = max_suit > (*(suit + i)) ? max_suit : *(suit + i);
                }
            }
            card_value += max_suit;
        }
    }
    else if (four_of_a_kind(num_r, num_s)){
        card_value += 8000;
        for (int i = RANK - 1; i >= 0; i--){
            if (*(num_r + i) == 4){
                card_value = card_value + i * 10;
                break;
            }
        }
        for (int i = SUIT - 1; i >= 0; i--){
            if (*(num_s + i) == 2){
                card_value = card_value + i;
                break;
            }
        }
    }
    else if (fullhouse(num_r, num_s)){
        card_value += 7000;
        int object_r;
        for (int i = RANK - 1; i >= 0; i--){
            if (*(num_r + i) == 3){
                card_value = card_value + i * 10;
                object_r = i;  // it means object's rank is (i+1).
                break;
            }
        }
        int max_suit = -1;
        for (int i = 0; i < 5; i++) {
            if (*(rank + i) == object_r) {
                max_suit = max_suit > (*(suit + i)) ? max_suit : *(suit + i);
            }
        }
        card_value += max_suit;
    }
    else if (three_of_a_kind(num_r, num_s)){
        card_value += 4000;
        int object_r;
        for (int i = RANK - 1; i >= 0; i--){
            if (*(num_r + i) == 3){
                card_value = card_value + i * 10;
                object_r = i;
                break;
            }
        }
        int max_suit = -1;
        for (int i = 0; i < 5; i++) {
            if (*(rank + i) == object_r) {
                max_suit = max_suit > (*(suit + i)) ? max_suit : *(suit + i);
            }
        }
        card_value += max_suit;
    }
    else if (two_pairs(num_r, num_s)){
        card_value += 3000;
        int object_r;
        for (int i = RANK - 1; i >= 0; i--){
            if (*(num_r + i) == 2){
                card_value = card_value + i * 10;
                object_r = i;
                break;
            }
        }
        int max_suit = -1;
        for (int i = 0; i < 5; i++) {
            if (*(rank + i) == object_r) {
                max_suit = max_suit > (*(suit + i)) ? max_suit : *(suit + i);
            }
        }
        card_value += max_suit;
    }
    else if (pair(num_r, num_s)){
        card_value += 2000;
        int object_r;
        for (int i = RANK - 1; i >= 0; i--){
            if (*(num_r + i) == 2){
                card_value = card_value + i * 10;
                object_r = i;
                break;
                break;
            }
        }
        int max_suit = -1;
        for (int i = 0; i < 5; i++){
            if (*(rank + i) == object_r){
                max_suit = max_suit > (*(suit + i)) ? max_suit : *(suit + i);
            }
        }
        card_value += max_suit;
    }
    else{
        card_value += 1000;
        int object_r;
        for (int i = RANK - 1; i >= 0; i--){
            if (*(num_r + i) == 1){
                card_value = card_value + i * 10;
                object_r = i;
                break;
            }
        }
        int max_suit = -1;
        for (int i = 0; i < 5; i++){
            if (*(rank + i) == object_r){
                max_suit = max_suit > (*(suit + i)) ? max_suit : *(suit + i);
            }
        }
        card_value += max_suit;
    }
    return card_value;
}
bool straight(const int *num_r, const int *num_s) {
    min_straight = false;
    if (num_r[12] == 1){
        for (int j = 0; j < 4; j++) {
            if (*(num_r + j) != 1)
                break;
            if (*(num_r + j) == 1 && j == 3) {
                min_straight = true;
                return true;
            }
        }
    }
    for (int i = 0; i < RANK - 4; i++) {
        if (*(num_r + i) == 1) {
            for (int j = 1; j <= 4; j++) {
                if (*(num_r + i + j) != 1)
                    return false;
            }
            return true;
        }
    }
}
bool flush(const int *num_r, const int *num_s){
    for (int i = 0; i < SUIT; i++) {
        if (*(num_s + i) == 5){
            return true;
        }
    }
    return false;
}
bool four_of_a_kind(const int *num_r, const int *num_s){
    for (int i = 0; i < RANK; i++){
        if (*(num_r + i) == 4)
            return true;
    }
    return false;
}
bool fullhouse(const int *num_r, const int *num_s){
    for (int i = 0; i < RANK; i++){
        if (*(num_r + i) == 3){
            for (int j = 0; j < RANK; j++){
                if (*(num_r + j) == 2)
                    return true;
            }
        }
    }
    return false;
}
bool three_of_a_kind(const int *num_r, const int *num_s){
    for (int i = 0; i < RANK; i++){
        if (*(num_r + i) == 3)
            return true;
    }
    return false;
}
bool two_pairs(const int *num_r, const int *num_s){
    for (int i = 0; i < RANK; i++){
        if (*(num_r + i) == 2){
            for (int j = i + 1; j < RANK; j++){
                if (*(num_r + j) == 2)
                    return true;
            }
        }
    }
    return false;
}
bool pair(const int *num_r, const int *num_s){
    for (int i = 0; i < RANK; i++){
        if (*(num_r + i) == 2)
            return true;
    }
    return false;
}