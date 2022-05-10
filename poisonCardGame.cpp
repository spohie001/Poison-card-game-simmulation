#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define SIZE 1000
#define CARDS 100
//*********************************
struct card
{
	int value;
	char color[7];
};
//*********************************
typedef struct p_c
{
	card player_cards;
	p_c* next;
}list;
//*********************************
struct card1
{
	int value;
	char color;
};
//*********************************
struct list1
{
	card1 player_cards;
	list1* next;
};
//*********************************
struct player_score
{
	int round_1;
	int round_2;
	int round_3;
};
//*********************************
struct player_eog
{
	int green_c = 0;
	int blue_c = 0;
	int red_c = 0;
	int violet_c = 0;
	int yellow_c = 0;
	int white_c = 0;
	int black_c = 0;
	int score = 0;
	int immunity[6] = { 0 };
};
//*********************************
void add_card(list1 *pile)
{
	list1* new_card = new list1[1];
	new_card->next= pile->next;
	pile->next = new_card;
}
//*********************************
void remove_after(list1* l) 
{
	if (l->next != NULL) {
		void* x = l->next;
		l->next = l->next->next;
		free(x);
	}
}
//*********************************
int write_values(card1* array, int a)
{
	
	for (int i = 0; i < a; i++)
	{
		cout << array[i].value << " ";
	}
	return 0;
}
//*********************************
int compare_gbrvywb(int g, int blu, int r, int v, int y, int w, int blck)
{
	int equal_or_not=0;
	if(g!=blu) equal_or_not = 1;
		if (g != r && r!=0) equal_or_not = 1;
			if (g != v && v != 0) equal_or_not = 1;
				if (g != y && y != 0) equal_or_not = 1;
					if (g != w && w != 0) equal_or_not = 1;
						if (g != blck && blck != 0) equal_or_not = 1;
	return equal_or_not;
}
//*********************************
int not_identical( int blu, int r, int v, int y, int w, int blck, card1* blue_cards, card1* red_cards, card1* violet_cards, card1* yellow_cards, card1* white_cards, card1* black_cards)
{
	cout << "The values of cards of all colors are not identical: "<<endl;
	if (blu != 0) cout << "blue cards values: "; write_values(blue_cards, blu); cout << endl;
	if (r != 0) cout << "red cards values: "; write_values(red_cards, r); cout << endl;
	if (v != 0) cout << "violet cards values: "; write_values(violet_cards, v); cout << endl;
	if (y != 0) cout << "yellow cards values: "; write_values(yellow_cards, y); cout << endl;
	if (w != 0) cout << "white cards values: "; write_values(white_cards, w); cout << endl;
	if (blck != 0) cout << "black cards values: "; write_values(black_cards, blck); cout << endl;
		return 0;
}
//*********************************
int compare_arrays_cd(int t, int blu, int r, int v, int y, int w, int blck, card1* array, card1* blue_cards, card1* red_cards, card1* violet_cards, card1* yellow_cards, card1* white_cards, card1* black_cards)
{
	int equal_or_not = 0;
	for (int i = 0; i < t; i++)
	{
		if (array[i].value != blue_cards[i].value && blu!=0)
		{
			equal_or_not = 1;
			return equal_or_not;
		}
		if (array[i].value != red_cards[i].value && r!=0)
		{
			equal_or_not = 1;
			return equal_or_not;
		}
		if (array[i].value != violet_cards[i].value &&v!=0)
		{
			equal_or_not = 1;
			return equal_or_not;
		}
		if (array[i].value != yellow_cards[i].value && y!=0)
		{
			equal_or_not = 1;
			return equal_or_not;
		}
		if (array[i].value != white_cards[i].value&&w!=0)
		{
			equal_or_not = 1;
			return equal_or_not;
		}
		if (array[i].value != black_cards[i].value && blck!=0)
		{
			equal_or_not = 1;
			return equal_or_not;
		}
	}
	return equal_or_not;
}

//*********************************
int compare_arrays_cd1(int t, int blu, int r, int v, int y, int w, int blck, card1* array, card1* blue_cards, card1* red_cards, card1* violet_cards, card1* yellow_cards, card1* white_cards, card1* black_cards)
{
	int comparr;
	if (t != 0)
	{
		comparr = compare_gbrvywb(t, blu, r, v, y, w, blck);
		if (comparr == 1)
		{
			not_identical(blu, r, v, y, w, blck, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards);
				return 1;
		}
		else if (comparr == 0)
		{
			if (compare_arrays_cd(t, blu, r, v, y, w, blck, array, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards) == 0)
				return 0;
			else if (compare_arrays_cd(t, blu, r, v, y, w, blck, array, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards) == 1)
			{
				not_identical(blu, r, v, y, w, blck, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards);
				return 1;
			}
		}
	}
	return 0;
}

//*********************************
int compare_arrays(int blu, int r, int v, int y, int w, int blck, card1* blue_cards, card1* red_cards, card1* violet_cards, card1* yellow_cards, card1* white_cards, card1* black_cards)
{
	if (compare_arrays_cd1(blu, blu, r, v, y, w, blck, blue_cards, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards) == 0)
		if (compare_arrays_cd1(r, blu, r, v, y, w, blck, red_cards, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards) == 0)
			if (compare_arrays_cd1(v, blu, r, v, y, w, blck, violet_cards, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards) == 0)
				if (compare_arrays_cd1(y, blu, r, v, y, w, blck, yellow_cards, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards) == 0)
					if (compare_arrays_cd1(w, blu, r, v, y, w, blck, white_cards, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards) == 0)
						if (compare_arrays_cd1(blck, blu, r, v, y, w, blck, black_cards, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards) == 0)
						{
							cout << "The values of cards of all colors are identical:\n";
							write_values(blue_cards, blu);
							cout << endl;
						}
	return 0;
}

//***************************************
void find_green_cards(int g ,card1 *green_cards)
{
	int equal_or_not = 0;
	if(g!=0)
	{
		for (int i = 0; i < g; i++)
		{
			for (int j = 0; j < g; j++)
			{
				if (green_cards[i].value != green_cards[j].value)
					equal_or_not = 1;
			}
		}

		if (equal_or_not == 0)
			cout << "Found " << g << " green cards, all with " << green_cards[0].value << " value"<<endl;
		else
			cout << "Different green cards values occurred"<<endl;
	}
	else
	{
		cout << "Green cards does not exist"<<endl;
	}
	}

int the_biggest1(card1* card_values, int o)
{
	if (o == 1)
		return 0;
	else
	{
		int b = the_biggest1(card_values, o - 1);
		return (card_values[b].value > card_values[o - 1].value ? b : o - 1);
	}
}
//***************************************
void change1(card1* card_values, int o, int b)
{
	card1 temp = card_values[o];
	card_values[o] = card_values[b];
	card_values[b] = temp;
}
//***************************************
void segregate_card_values1(card1* card_values, int o)
{
	if (o > 1)
	{
		change1(card_values, o - 1, the_biggest1(card_values, o));
		segregate_card_values1(card_values, o - 1);
	}
}
//*********************************
void segregate_into_arrays(int g, card1* green_cards, int place_in_cnntd_vc, card1 *cnntd_vc, char color)
{
	for (int i = 0, j = 0; i < place_in_cnntd_vc && j < g; i++)
	{
		if (cnntd_vc[i].color == color)
		{
			green_cards[j] = cnntd_vc[i];
			j++;
		}
		
	}
}
//*********************************
void counting_cards(int& g, int& b, int& r, int& v, int& y, int& w, int& blck, int place_in_cnntd_vc, card1* cnntd_vc)
{
	for (int i = 0; i < place_in_cnntd_vc; i++)
	{
		if (cnntd_vc[i].color == 'g')
			g++;
		else if (cnntd_vc[i].color == 'b')
			b++;
		else if (cnntd_vc[i].color == 'r')
			r++;
		else if (cnntd_vc[i].color == 'v')
			v++;
		else if (cnntd_vc[i].color == 'y')
			y++;
		else if (cnntd_vc[i].color == 'w')
			w++;
		else if (cnntd_vc[i].color == 'c')
			blck ++;
	}}
//*********************************
list1* segregate_pile_hand_deck(char* token, list1* cur)
{
	if (token == NULL)
	{
	}
	else if ((int)token[0] <= 57)
	{
		add_card(cur);
		cur = cur->next;
		cur->player_cards.value = atoi(token);
	}
	else
	{
		if (strcmp(token, "black") == 0)
			cur->player_cards.color = 'c';

		else if (strcmp(token, "green") == 0 || strcmp(token, "blue") == 0 || strcmp(token, "red") == 0 || strcmp(token, "yellow") == 0 || strcmp(token, "white") == 0 || strcmp(token, "black") == 0 || strcmp(token, "violet") == 0)
			cur->player_cards.color = token[0];
	}

	return cur;
}
//*********************************
int check_pile_colors(list1* pile,  int number_of_piles)
{
	int game_state = 0;
	
	for (int i = 0; i < number_of_piles; i++)
	{
		list1* helper = pile + i;
		if(helper->next!=NULL)
		helper = helper->next;
		list1* another_helper = helper->next;

		while (another_helper != NULL)
		{
				if (helper->player_cards.color != another_helper->player_cards.color && helper->player_cards.color != 'g' && another_helper->player_cards.color != 'g')
				{
					cout << "Two different colors were found on the " << i + 1 << " pile\n";
					game_state = 1;
					break;
				}
				another_helper = another_helper->next;
			}
		}
	
	return game_state;
}
//*********************************
int	check_expl(list1* pile, int* cards_in_pilex2, int number_of_piles, int expl)
{
	int game_state = 0;
	list1* curr;

	for (int i = 0; i < number_of_piles; i++)
	{
		int compare = 0;
		curr = pile + i;
		curr = curr->next;

		while(curr!=NULL)
		{
			compare += curr->player_cards.value;
			curr = curr->next;
		}
		if (compare > expl)
		{
			cout << "Pile number " << i+1 << " should explode earlier\n";
			game_state = 1;
		}
	}

	return game_state;
}
//*********************************
int check_hand_cards(int *cards_in_handx2, int act, int cards, int ppl)
{
	int game_state = 0;

	int more = cards % ppl;			//wiem którzy grzcze mieli rozdane wiêcej kart
	
			if (act >= (more+1) && act <= ppl)
			{
				for (int i = act+1; i <= ppl; i++)
				{
					if ( (cards_in_handx2[i] / 2)!=(cards_in_handx2[act] / 2))
					{
						cout << "The number of players cards on hand is wrong\n";
						game_state = 1;
						return game_state;
					}

				}
				for (int i = more + 1; i <= act - 1; i++)
				{
					if ((cards_in_handx2[i] / 2) != ((cards_in_handx2[act] / 2) - 1))
					{
						cout << "The number of players cards on hand is wrong\n";
						game_state = 1;
						return game_state;
					}
				}
				for (int i = 1; i <= more; i++)
				{
					if ((cards_in_handx2[i] / 2) != ((cards_in_handx2[act] / 2)))
					{
						cout << "The number of players cards on hand is wrong\n";
						game_state = 1;
						return game_state;
					}
				}
			}
			else if (act >= 1 && act <= more)
			{
				for (int i =1; i <=act-1; i++)
				{
					if ((cards_in_handx2[i] / 2) != ((cards_in_handx2[act] / 2)-1))
					{
						cout << "The number of players cards on hand is wrong\n";
						game_state = 1;
						return game_state;
					}
				}
				for (int i = act+1; i <= more; i++)
				{
					if ((cards_in_handx2[i] / 2) != (cards_in_handx2[act] / 2))

					{
						cout << "The number of players cards on hand is wrong\n";
						game_state = 1;
						return game_state;
					}
				}
				for (int i = more+1; i <= ppl; i++)
				{
					if ((cards_in_handx2[i] / 2) != ((cards_in_handx2[act] / 2) - 1))
					{
						cout << "The number of players cards on hand is wrong\n";
						game_state = 1;
						return game_state;
					}
				}

			}
	

	return game_state;
}
//*********************************
int segregate_cards(char* token, card1* cnntd_vc, int place_in_cnntd_vc)
{

	if (token == NULL)
	{
	}
	else if ((int)token[0] <= 57)
		cnntd_vc[place_in_cnntd_vc].value = atoi(token);
	else
	{
		if (strcmp(token, "black")==0)
		{
			cnntd_vc[place_in_cnntd_vc].color = 'c';
			place_in_cnntd_vc++;
		}
		else if(strcmp(token, "green")==0|| strcmp(token, "blue") == 0 || strcmp(token, "red") == 0 || strcmp(token, "yellow") == 0 || strcmp(token, "white") == 0 || strcmp(token, "black") == 0 || strcmp(token, "violet") == 0)
		{
			cnntd_vc[place_in_cnntd_vc].color = token[0];
			place_in_cnntd_vc++;
		}
	}
	return place_in_cnntd_vc;
}
//*********************************
char see_if_hand_deck(char* array)
{
	if (strcmp(array, "deck") == 0)
		return 'd';
	else if (strcmp(array, "hand") == 0)
		return 'h';
	return 'e'; //error
}
//*********************************
int count_colors(int* array)
{
	int sum = 0;
	for (int i = 0; i < 6; i++)
	{
		sum += array[i];
	}
	return sum;
}
//*********************************
int find_colors(int* array, char* token)
{
	if (token == NULL)
		return 0;
	else if (strcmp(token, "blue") == 0)
		array[0] = 1;
	else if (strcmp(token, "red") == 0)
		array[1] = 1;
	else if (strcmp(token, "violet") == 0)
		array[2] = 1;
	else if (strcmp(token, "yellow") == 0)
		array[3] = 1;
	else if (strcmp(token, "white") == 0)
		array[4] = 1;
	else if (strcmp(token, "black") == 0)
		array[5] = 1;
	else if (strcmp(token, "green") == 0)
		array[6] = 1;

	return 0;
}
//*********************************
int find_empty_pile(char color_to_find, list1* pile, int n_piles)
{
	int only_green = 0;
	for (int i = 0; i < n_piles; i++)
	{
		list1* cur = pile + i;
		cur = cur->next;
		if (cur == NULL)
			return i;

		while (cur != NULL)
		{
			if (cur->player_cards.color != 'g')
				only_green = 1;
			cur = cur->next;
		}
		if (only_green == 0)
			return i;
	}
	return -1;
}

//*********************************
int find_pile_with_color(char color_to_find, list1* pile, int n_piles)
{
	if (color_to_find == 'g')
		return 0;
	for (int i = 0; i < n_piles; i++)
	{
		list1* cur = pile + i;
		cur = cur->next;

		while (cur != NULL)
		{
			if (cur->player_cards.color == color_to_find)
				return i;
			cur = cur->next;
		}
	}
	return find_empty_pile( color_to_find,  pile,  n_piles);
}
//*********************************
void explode(list1* deck, list1* pile, int i, int exp)
{
	list1* temp = deck;
	list1* cur = pile + i;
	if(cur!=NULL)
	cur = cur->next;
	while (temp->next != NULL)
		temp = temp->next;
	while (cur != NULL)
	{
		add_card(temp);
		temp = temp->next;
		temp->player_cards.color = cur->player_cards.color;
		temp->player_cards.value = cur->player_cards.value;
		cur = cur->next;
		remove_after(pile + i);
	}
}
//*********************************
void check_pile_explosion(list1* deck, list1* pile,  int i, int exp)
{
	list1* check = pile + i;
	check = check->next;
	int sum = 0;
	while (check != NULL)
	{
		sum += check->player_cards.value;
		check = check->next;
	}

	if (sum > exp)
		explode(deck, pile, i, exp);

}
//*********************************
void eazy_move( list1* cards, list1* pile, list1* deck, int n_piles, int exp )
{
	list1* card_to_go;
	char color_to_find;
	if (cards->next != NULL)
	{
		card_to_go = cards->next;
		color_to_find = card_to_go->player_cards.color;

		int i = find_pile_with_color(color_to_find, pile, n_piles);

		list1* curr = pile + i;
		while (curr->next != NULL)
			curr = curr->next;
		add_card(curr);
		curr = curr->next;
		curr->player_cards.color = card_to_go->player_cards.color;
		curr->player_cards.value = card_to_go->player_cards.value;
		remove_after(cards);
		check_pile_explosion(deck, pile, i, exp);
	}
}
//*********************************
void decode_color(list1 *curr)
{
	if (curr->player_cards.color == 'g')
		cout << "green";
	else if (curr->player_cards.color == 'b')
		cout << "blue";
	else if (curr->player_cards.color == 'r')
		cout << "red";
	else if (curr->player_cards.color == 'v')
		cout << "violet";
	else if (curr->player_cards.color == 'y')
		cout << "yellow";
	else if (curr->player_cards.color == 'w')
		cout << "white";
	else if (curr->player_cards.color == 'c')
		cout << "black";
			
}
//*********************************
void fdecode_color(list1* curr, FILE * file1)
{
	if (curr->player_cards.color == 'g')
	fprintf(file1, "green ");
	else if (curr->player_cards.color == 'b')
		fprintf(file1, "blue ");
	else if (curr->player_cards.color == 'r')
			fprintf(file1, "red ");
	else if (curr->player_cards.color == 'v')
				fprintf(file1, "violet ");
	else if (curr->player_cards.color == 'y')
					fprintf(file1, "yellow ");
	else if (curr->player_cards.color == 'w')
						fprintf(file1, "white ");
	else if (curr->player_cards.color == 'c')
							fprintf(file1, "black ");

}
//*********************************
void print_game_status(int ac_pl, int n, int expl, list1 *hand, list1 *deck, list1 *pile, int n_piles)
{
	int m = (ac_pl+1) % n;
	if (m == 0) m = n;
	cout << "active player = " << m << endl;
	cout << "players number = " << n << endl;
	cout << "explosion threshold = " << expl << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " player hand cards: ";

		list1* cur = hand + i;
		cur = cur->next;
		while (cur != NULL)
		{
			cout << cur->player_cards.value;
			cout << " ";
			decode_color(cur);
			cout << " ";
			cur = cur->next;
		}
		cout << endl;

		cout << i + 1 << " player deck cards: ";
		cur = deck + i;
		cur = cur->next;
		while (cur != NULL)
		{
			cout << cur->player_cards.value;
			cout << " ";
			decode_color(cur);
			cout << " ";
			cur = cur->next;
		}
		cout << endl;
	}
	for (int i = 1; i <= n_piles; i++)
	{
		cout << i << " pile cards: ";
		list1* cur = pile + i -1;
		cur = cur->next;
		while (cur != NULL)
		{
			cout << cur->player_cards.value;
			cout << " ";
			decode_color(cur);
			cout << " ";
			cur = cur->next;
		}
		cout << endl;
	}
}
//*********************************
void fprint_game_status(FILE* file1, int ac_pl, int n, int expl, list1* hand, list1* deck, list1* pile, int n_piles)
{
	int m = (ac_pl + 1) % n;
	if (m == 0) m = n;

	if (file1 == NULL) {
		cout << "Otwarcie pliku nie powiod³o siê\n";
	}
	else
	{
		int m = (ac_pl + 1) % n;
		if (m == 0) m = n;
		fprintf(file1, "active player = %d\n", m);
		fprintf(file1, "players number = %d\n", n);
		fprintf(file1, "explosion threshold = %d\n", expl);

		for (int i = 0; i < n; i++)
		{
			fprintf(file1, "%d player hand cards: ", i + 1);

			list1* cur = hand + i;
			cur = cur->next;
			while (cur != NULL)
			{
				fprintf(file1, "%d ", cur->player_cards.value);
				fdecode_color(cur, file1);
				cur = cur->next;
			}
			fprintf(file1, "\n");
			fprintf(file1, "%d player deck cards: ", i + 1);
			cur = deck + i;
			cur = cur->next;
			while (cur != NULL)
			{
				fprintf(file1, "%d ", cur->player_cards.value);
				fdecode_color(cur, file1);
				cur = cur->next;
			}
			fprintf(file1, "\n");
		}
		for (int i = 1; i <= n_piles; i++)
		{
			fprintf(file1, "%d pile cards: ", i);
			list1* cur = pile + i - 1;
			cur = cur->next;
			while (cur != NULL)
			{
				fprintf(file1, "%d ", cur->player_cards.value);
				fdecode_color(cur, file1);
				cur = cur->next;
			}
			fprintf(file1, "\n");
		}
	}
}
//*********************************
void count_score(player_eog* game_players, int num_pl, player_score* player_points, int round)
{
	int* score;
	score = new int[num_pl];
	score[num_pl] = { 0 };
	for (int k = 0; k < num_pl; k++)
	{
		score[k] = 2 * game_players[k].green_c + game_players[k].blue_c + game_players[k].red_c + game_players[k].violet_c + game_players[k].yellow_c + game_players[k].white_c + game_players[k].black_c;
		if (round == 1)
			player_points[k].round_1 = score[k];
		else if (round == 2)
			player_points[k].round_2 = score[k];
		else if (round == 3)
			player_points[k].round_3 = score[k];

		cout << "Wynik gracza " << k + 1 << " = " << score[k] << endl;
	}
}
//*********************************
void give_immunity(player_eog* game_players, int num_pl)
{
	for (int k = 0; k < num_pl; k++)
	{
		if (game_players[k].immunity[0] == 0)
		{
			game_players[k].blue_c = 0;
			cout << "Na kolor blue odporny jest gracz " << k+1 << endl;
		}
		if (game_players[k].immunity[1] == 0)
		{
			game_players[k].red_c = 0;
			cout << "Na kolor red odporny jest gracz " << k + 1 << endl;
		}
		if (game_players[k].immunity[2] == 0)
		{
			game_players[k].violet_c = 0;
			cout << "Na kolor violet odporny jest gracz " << k + 1 << endl;
		}
		if (game_players[k].immunity[3] == 0)
		{
			game_players[k].yellow_c = 0;
			cout << "Na kolor yellow odporny jest gracz " << k + 1 << endl;
		}
		if (game_players[k].immunity[4] == 0)
		{
			game_players[k].white_c = 0;
			cout << "Na kolor white odporny jest gracz " << k + 1 << endl;
		}
		if (game_players[k].immunity[5] == 0)
		{
			game_players[k].black_c = 0;
			cout << "Na kolor black odporny jest gracz " << k + 1 <<endl;
		}
	}
}
//*********************************
void find_immunity(player_eog* game_players, int num_pl)
{
	for (int j = 0; j < num_pl; j++)
	{
		for (int k = 0; k < j; k++)
		{
			if (game_players[j].blue_c <= game_players[k].blue_c)
				game_players[j].immunity[0] = 1;

			if (game_players[j].red_c <= game_players[k].red_c)
				game_players[j].immunity[1] = 1;

			if (game_players[j].violet_c <= game_players[k].violet_c)
					game_players[j].immunity[2] = 1;

			if (game_players[j].yellow_c <= game_players[k].yellow_c)
				game_players[j].immunity[3] = 1;

			if (game_players[j].white_c <= game_players[k].white_c)
					game_players[j].immunity[4] = 1;

			if (game_players[j].black_c <= game_players[k].black_c)
				game_players[j].immunity[5] = 1;


		}
		for (int k = j+1; k < num_pl; k++)
		{
			if (game_players[j].blue_c <= game_players[k].blue_c)
				game_players[j].immunity[0] = 1;

			if (game_players[j].red_c <= game_players[k].red_c)
				game_players[j].immunity[1] = 1;

			if (game_players[j].violet_c <= game_players[k].violet_c)
				game_players[j].immunity[2] = 1;

			if (game_players[j].yellow_c <= game_players[k].yellow_c)
				game_players[j].immunity[3] = 1;

			if (game_players[j].white_c <= game_players[k].white_c)
				game_players[j].immunity[4] = 1;

			if (game_players[j].black_c <= game_players[k].black_c)
				game_players[j].immunity[5] = 1;
		}

	}
	give_immunity(game_players, num_pl);
}
//*********************************
void count_cards(list1* deck_cards,player_eog* game_players)
{
	list1* temp = deck_cards;
	while (temp != NULL)
	{
		if (temp->player_cards.color == 'g')
			game_players->green_c++;
		else if (temp->player_cards.color == 'b')
			game_players->blue_c++;
		else if (temp->player_cards.color == 'r')
			game_players->red_c++;
		else if (temp->player_cards.color == 'v')
			game_players->violet_c++;
		else if (temp->player_cards.color == 'y')
			game_players->yellow_c++;
		else if (temp->player_cards.color == 'w')
			game_players->white_c++;
		else if (temp->player_cards.color == 'c')
			game_players->black_c++;
		temp = temp->next;
	}
}
//*********************************
void end_the_game(list1* deck_cards, int pl_num, player_score* player_points, int round)
{
	player_eog* game_players;
	game_players = new player_eog[pl_num];
	for (int k = 0; k < pl_num; k++)
		count_cards((deck_cards + k)->next, game_players + k);
	find_immunity(game_players, pl_num);
	count_score(game_players, pl_num, player_points, round);
	delete[] game_players;
	game_players = NULL;
}
//*********************************
int fprint_cards(list* hand_cards, int k, int n, int e, FILE* aaaa)
{


	if (aaaa == NULL) {
		cout << "Otwarcie pliku nie powiod³o siê\n";
		return 1;
	}
	else
	{
		fprintf(aaaa, "active player = 1\n");
		fprintf(aaaa, "players number = %d\n", n);
		fprintf(aaaa, "explosion threshold = %d\n", e);

		for (int i = 0; i < n; i++)
		{
			fprintf(aaaa, "%d player hand cards: ", i + 1);

			list* cur = hand_cards[i].next;

			while (cur != NULL)
			{
				fprintf(aaaa, "%d ", cur->player_cards.value);
				fprintf(aaaa, "%s ", cur->player_cards.color);
				cur = cur->next;
			}
			fprintf(aaaa, "\n");
			fprintf(aaaa, "%d player deck cards: \n", i + 1);

		}
		for (int i = 1; i <= k; i++)
		{
			fprintf(aaaa, "%d pile cards: \n", i);
		}
	}

	return 0;
}
//***************************************
int print_cards(list* hand_cards, int k, int n, int e)
{
	cout << "active player = 1" << endl;
	cout << "players number = " << n << endl;
	cout << "explosion threshold = " << e << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << " player hand cards: ";


		list* cur = hand_cards[i].next;

		while (cur != NULL)
		{
			cout << cur->player_cards.value;
			cout << " ";
			cout << cur->player_cards.color;
			cout << " ";
			cur = cur->next;
		}
		cout << endl;
		cout << i + 1 << " player deck cards: " << endl;

	}
	for (int i = 1; i <= k; i++)
	{
		cout << i << " pile cards:" << endl;
	}

	return 0;
}
//***************************************
int add_card(list* hand_cards, card** deck, int i, int j)
{
	list* new_card = new list[1];
	new_card->player_cards = deck[i][j];
	new_card->next = hand_cards->next;
	hand_cards->next = new_card;
	return 0;
}
//***************************************
int generate_hand_cards(int n, int k, int g, int o, int e, list* hand_cards, card** deck)
{
	for (int i = 0; i < n; i++)
	{
		list* cur = hand_cards + i;
		for (int dg = i; dg < g; dg += n)
		{
			int w = 0;
			add_card(cur, deck, w, dg);
			cur = cur->next;
		}
		for (int dk = 1; dk <= k; dk++)
		{
			for (int d_o = 0; d_o < o; d_o++)
			{
				if ((g + (dk - 1) * o + d_o) % n == i)
				{
					add_card(cur, deck, dk, d_o);
					cur = cur->next;
				}
			}
		}
	}
	print_cards(hand_cards, k, n, e);
	return 0;
}
//***************************************
int generate_deck_colors(card** deck, int k, int g, int o)
{
	for (int j = 0; j < g; j++)
	{
		deck[0][j].color[0] = 'g';		//nadanie zielonym koloru
		deck[0][j].color[1] = 'r';
		deck[0][j].color[2] = 'e';
		deck[0][j].color[3] = 'e';
		deck[0][j].color[4] = 'n';
		deck[0][j].color[5] = '\0';
	}
	if (k >= 1)
	{
		for (int j = 0; j < o; j++)
		{
			deck[1][j].color[0] = 'b';
			deck[1][j].color[1] = 'l';
			deck[1][j].color[2] = 'u';
			deck[1][j].color[3] = 'e';
			deck[1][j].color[4] = '\0';
		}
	}
	if (k >= 2)
	{
		for (int j = 0; j < o; j++)

		{
			deck[2][j].color[0] = 'r';
			deck[2][j].color[1] = 'e';
			deck[2][j].color[2] = 'd';
			deck[2][j].color[3] = '\0';
		}
	}
	if (k >= 3)
	{
		for (int j = 0; j < o; j++)
		{
			deck[3][j].color[0] = 'v';
			deck[3][j].color[1] = 'i';
			deck[3][j].color[2] = 'o';
			deck[3][j].color[3] = 'l';
			deck[3][j].color[4] = 'e';
			deck[3][j].color[5] = 't';
			deck[3][j].color[6] = '\0';
		}
	}
	if (k >= 4)
	{
		for (int j = 0; j < o; j++)
		{
			deck[4][j].color[0] = 'y';
			deck[4][j].color[1] = 'e';
			deck[4][j].color[2] = 'l';
			deck[4][j].color[3] = 'l';
			deck[4][j].color[4] = 'o';
			deck[4][j].color[5] = 'w';
			deck[4][j].color[6] = '\0';
		}
	}
	if (k >= 5)
	{
		for (int j = 0; j < o; j++)
		{
			deck[5][j].color[0] = 'w';
			deck[5][j].color[1] = 'h';
			deck[5][j].color[2] = 'i';
			deck[5][j].color[3] = 't';
			deck[5][j].color[4] = 'e';
			deck[5][j].color[5] = '\0';
		}
	}
	if (k >= 6)
	{
		for (int j = 0; j < o; j++)
		{
			deck[6][j].color[0] = 'b';
			deck[6][j].color[1] = 'l';
			deck[6][j].color[2] = 'a';
			deck[6][j].color[3] = 'c';
			deck[6][j].color[4] = 'k';
			deck[6][j].color[5] = '\0';
		}
	}

	return 0;
}
//***************************************
void shuffle(card** deck, int k, int g, int o)
{
	card temp;
	int randomg, randomo_y, randomo_x, randomo_xx, randomo_yy;
	for (int j= 0; j < g; j++)
	{
		randomg = rand() % g ;
		randomo_y = rand() % k + 1;
		randomo_x = rand() % o ;
		temp = deck[0][randomg];
		deck[0][randomg] = deck[randomo_y][randomo_x];
		deck[randomo_y][randomo_x] = temp;
	}
	for (int j = 0; j < k*o; j++)
	{
		randomo_y = rand() % k + 1;
		randomo_x = rand() % o ;
		randomo_yy = rand() % k + 1;
		randomo_xx = rand() % o;
		temp = deck[randomo_y][randomo_x];
		deck[randomo_y][randomo_x] = deck[randomo_yy][randomo_xx];
		deck[randomo_yy][randomo_xx] = temp;
	}
}
//***************************************
card** generate_deck_values(int k, int g, int gv, int o, int* card_values)
{
	card** deck = new card * [g + k * o];

	deck[0] = new card[g];		//tworzenie miejsca na zielone karty

	for (int i = 1; i <= k; i++)
	{
		deck[i] = new card[o];		//tworzenie miejsca na inne kolory
	}
	for (int j = 0; j < g; j++)
	{
		deck[0][j].value = gv;		//nadanie zielonym wartoœci

	}
	for (int j = 1; j <= k; j++)
	{
		for (int i = 0; i < o; i++)
		{
			deck[j][i].value = card_values[i];		//nadanie warwoœci reszcie kolorow
		}
	}
	generate_deck_colors(deck, k, g, o);
	shuffle(deck, k, g, o);
	return deck;
}
//***************************************
int the_biggest(int* card_values, int o)
{
	if (o == 1)
		return 0;
	else
	{
		int b = the_biggest(card_values, o - 1);
		return (card_values[b] > card_values[o - 1] ? b : o - 1);
	}
}
//***************************************
void change(int* card_values, int o, int b)
{
	int temp = card_values[o];
	card_values[o] = card_values[b];
	card_values[b] = temp;
}
//***************************************
void delete_hdp(list1* cards_on_hand, int n)
{
	list1* dele = cards_on_hand;
	for (int i = 0; i < n; i++)
	{
		if (cards_on_hand != NULL)
		{
			list1* cur = cards_on_hand[i].next;
			if (cur != NULL)
			{
				list1* temp = cur->next;

				for (int j = 0; cur != NULL; j++)
				{
					delete[] cur;
					cur = temp;
					if (temp != NULL)
						temp = temp->next;
				}
			}
			else
				delete[] cur;
		}
	}
	delete[] dele;
	dele = NULL;
}
//***************************************
void count_cards_hdp(int pl_num,int* players_handx2, int* players_deckx2, int number_of_piles, int* cards_in_pilex2)
{
	for (int i = 1; i <= pl_num; i++)
	{
		cout << i << " player has " << players_handx2[i] / 2 << " cards on hand" << endl;
		cout << i << " player has " << players_deckx2[i] / 2 << " cards in front of him" << endl;
	}
	for (int i = 1; i <= number_of_piles; i++)
		cout << "there are " << cards_in_pilex2[i] / 2 << " cards on " << i << " pile" << endl;
}
//***************************************
void check_game_state(int* players_handx2, int ac_pl, int place_in_cnntd_vc,int pl_num, list1* pile_cards,int number_of_piles, int* cards_in_pilex2, int expl)
{
	int game_state[3];
	game_state[0] = check_hand_cards(players_handx2, ac_pl, place_in_cnntd_vc, pl_num);
	game_state[1] = check_pile_colors(pile_cards, number_of_piles);
	game_state[2] = check_expl(pile_cards, cards_in_pilex2, number_of_piles, expl);


	int state_of_game = 0;
	for (int i = 0; i < 3; i++)
		state_of_game += game_state[i];
	if (state_of_game == 0)
		cout << "Current state of the game is ok" << endl;
}
//***************************************
void segregare_card_colors(int g, int blu, int r, int v, int y, int w, int blck,card1 *green_cards, card1 *blue_cards, card1 *red_cards, card1 *violet_cards, card1 *yellow_cards, card1 *white_cards, card1* black_cards, int place_in_cnntd_vc, card1* cnntd_vc)
{
	if (g != 0)
	{
		segregate_into_arrays(g, green_cards, place_in_cnntd_vc, cnntd_vc, 'g');
		find_green_cards(g, green_cards);
	}
	if (blu != 0)
	{
		segregate_into_arrays(blu, blue_cards, place_in_cnntd_vc, cnntd_vc, 'b');
		segregate_card_values1(blue_cards, blu);
	}
	if (r != 0)
	{
		segregate_into_arrays(r, red_cards, place_in_cnntd_vc, cnntd_vc, 'r');
		segregate_card_values1(red_cards, r);

	}
	if (v != 0)
	{
		segregate_into_arrays(v, violet_cards, place_in_cnntd_vc, cnntd_vc, 'v');
		segregate_card_values1(violet_cards, v);
	}
	if (y != 0)
	{
		segregate_into_arrays(y, yellow_cards, place_in_cnntd_vc, cnntd_vc, 'y');
		segregate_card_values1(yellow_cards, y);
	}
	if (w != 0)
	{
		segregate_into_arrays(w, white_cards, place_in_cnntd_vc, cnntd_vc, 'w');
		segregate_card_values1(white_cards, w);
	}
	if (blck != 0)
	{
		segregate_into_arrays(blck, black_cards, place_in_cnntd_vc, cnntd_vc, 'c');
		segregate_card_values1(black_cards, blck);
	}
}
//***************************************
void number_of_cards(int blu, int r, int v, int y, int w, int blck)
{
	int sum_of_cards = 0, s = 0;

	if (blu > 0) sum_of_cards += blu;
	if (r > 0) sum_of_cards += r;
	if (v > 0) sum_of_cards += v;
	if (y > 0) sum_of_cards += y;
	if (w > 0) sum_of_cards += w;
	if (blck > 0) sum_of_cards += blck;
	if (blu > 0) s++;
	if (r > 0) s++;
	if (v > 0) s++;
	if (y > 0) s++;
	if (w > 0) s++;
	if (blck > 0) s++;

	if (sum_of_cards % s == 0)
		cout << "The number cards of all colors is equal: " << blu << endl;
	else
	{
		cout << "At least two colors with a different number of cards were found:" << endl;
		cout << "blue cards are " << blu << endl;
		cout << "red cards are " << r << endl;
		cout << "violet cards are " << v << endl;
		cout << "yellow cards are " << y << endl;
		cout << "white cards are " << w << endl;
		cout << "black cards are " << blck << endl;
	}
}
//********************************************
void in_case_of_error()
{
	cout << "Ups! Chyba zosta³y podane z³e dane!\nSpróbujmy jeszcze raz.";
}
//***************************************
int the_smallest(int* scores , int pl_num)
{
	if (pl_num == 1)
		return 0;
	else
	{
		int s = the_smallest(scores, pl_num - 1);
		return (scores[s] < scores[pl_num - 1] ? s : pl_num-1);
	}
}
//***************************************
void the_final_countdown(player_score* player_points, int pl_num)
{
	int* scores;
	scores = new  int[pl_num];
	for (int i = 0; i < pl_num; i++)
		scores[i] = player_points[i].round_1 + player_points[i].round_2 + player_points[i].round_3;
	int winner = the_smallest(scores, pl_num);

	cout << "------------------------------>>>>>>>KONIEC GRY<<<<<<<---------------------------------\n";
	for (int i = 0; i < pl_num; i++)
		cout << "Gracz " << i + 1 << " zdoby³ " << scores[i] << " punktów.\n";

	int remis = 0;
	
	for (int i = 0; i < pl_num; i++)
	{
		if (scores[i] == scores[winner] && i!=winner)
		{
			cout << "------------------------------->>>>>>> REMIS GRACZ " << i + 1 << "!!! GRATULACJE!!!<<<<<<<-----------------------------------\n";
			remis = 1;
		}
	}

	if (remis == 0)
	cout<<"------------------------------->>>>>>> WYGRA£ GRACZ "<< winner+1 <<"!!! GRATULACJE!!!<<<<<<<-----------------------------------\n";
	else if(remis == 1)
	cout << "------------------------------->>>>>>> REMIS GRACZ " << winner + 1 << "!!! GRATULACJE!!!<<<<<<<-----------------------------------\n";

}

//***************************************************JENDOKROTNE(NA POCZ¥TKU GRY) POBRANIE INFORMACJI********************************************************************************************//
int main()
{
		srand(time(NULL));
		setlocale(LC_ALL, "polish");

		int n, e, k, gr, gv, o, card_values[20];
		cout << "Witaj w uogólnionej wersji gry \"Trucizna\".\nUstaw, proszê parametry gry wed³ug w³asnych preferencji.\nMi³ej gry!!\n";
		cout << "Liczba graczy: ";
		cin >> n; cout << endl;
		cout << "Wartoœæ, po krórej przekroczeniu, eksploduje kocio³ek: ";
		cin >> e; cout << endl;
		cout << "Liczba kolorów kart(max 6): ";
		cin >> k; cout << endl;
		cout << "Liczba zielonych kart: ";
		cin >> gr; cout << endl;
		cout << "Wartoœæ zieonych kart: ";
		cin >> gv; cout << endl;
		cout << "Liczba kart kolorów innych ni¿ zielony(max 100): ";
		cin >> o; cout << endl;
		cout << " Wartoœci kart kolorów innych ni¿ zielony: ";
		for (int i = 0; i < o; i++)
		{
			cin >> card_values[i];
		}

		cout << "\n\n\nPowodzenia!!\n\n\n";
		//************************************************ROZPOCZÊCIE GRY***********************************************************************************************//

		//************************************************RUNDA I WYNIKI GRACZY***********************************************************************************************//
	int round_nr = 1;
	player_score* player_points;
	player_points = new player_score[n];
	for (int i = 0; i < n; i++)
	{
		player_points->round_1 = 0;
		player_points->round_2 = 0;
		player_points->round_3 = 0;
	}
	while (round_nr <= 3)		//pêtla dla 3 rund
	{
		//************************************************GENEROWANIE KART NA RÊKU***********************************************************************************************//
		card** deck = generate_deck_values(k, gr, gv, o, card_values);
		list* hand_cards;
		hand_cards = new list[n];
		for (int i = 0; i < n; i++)
			hand_cards[i].next = NULL;
		cout << "-------------------------------------->>>>ROUND "<<round_nr<<"<<<<--------------------------------------" << endl;
		generate_hand_cards(n, k, gr, o, e, hand_cards, deck);
		//*************************************************ZAPISYWANIE STANU GRY W PLIKU**********************************************************************************************//
		FILE* file1;
		file1 = fopen("plik.txt", "w");
		fprint_cards(hand_cards, k, n, e, file1);
		fclose(file1);
		//*************************************************DEALOKACJA PAMIÊCI**********************************************************************************************//
		for (int i = 0; i < k + 1; i++)
		{
			delete[] deck[i];
			deck[i] = NULL;
		}
			delete[] deck;
			deck = NULL;

		list* dele = hand_cards;
		for (int i = 0; i < n; i++)
		{
			list* cur = hand_cards[i].next;

			if (cur != NULL)
			{
				list* temp = cur->next;

				while (cur != NULL)
				{
					delete[] cur;
					cur = temp;
					if (temp != NULL)
						temp = temp->next;
				}
			}
		}
		delete[] dele;
		dele = NULL;
		//**************************************************************SPRAWDZANIE STANU GRY 1.*********************************************************************************//
		
		while (1)		//pêtla powtarzaj¹ca siê a¿ do koñca rundy
		{
			char word[10];
			int ac_pl, pl_num = 0;
			int number_of_colors[7] = { 0 };
			char line[SIZE];
			char* token;
			int expl;

			card1 cnntd_vc[CARDS];
			int place_in_cnntd_vc = 0;

			file1 = fopen("plik.txt", "r");

			//**************************************************************AKTYWNY GRACZ, ILOŒÆ GRACZY, EKSPLOZJA KOCIO£KA*********************************************************************************//
			while (1)		//pêtla powtarzaj¹ca siê a¿ do pobrania wartoœci dla eksplozji kocio³ka
			{
				fscanf(file1, "%s", word);
				if (strcmp(word, "active") == 0)
				{
					fscanf(file1, "%s", word);
					fscanf(file1, "%s", word);
					fscanf(file1, "%d", &ac_pl);
				}
				else if ((strcmp(word, "players") == 0))
				{
					fscanf(file1, "%s", word);
					fscanf(file1, "%s", word);
					fscanf(file1, "%d", &pl_num);
				}
				else if ((strcmp(word, "explosion") == 0))
				{
					fscanf(file1, "%s", word);
					fscanf(file1, "%s", word);
					fscanf(file1, "%d", &expl);
					break;
				}
			}
			//**************************************************************KARTY NA RÊKU I PRZED GRACZEM*********************************************************************************//

			//**************************************************************ZMIENNE
			int* players_handx2;
			int* players_deckx2;
			players_handx2 = new int[pl_num + 1];
			players_deckx2 = new int[pl_num + 1];
			for (int k = 0; k <= pl_num; k++)
			{
				players_handx2[k] = 0;
				players_deckx2[k] = 0;
			}

			list1* cards_on_hand;
			cards_on_hand = new list1[pl_num];
			for (int i = 0; i < pl_num; i++)
				cards_on_hand[i].next = NULL;

			list1* cards_pl_deck;
			cards_pl_deck = new list1[pl_num];
			for (int i = 0; i < pl_num; i++)
				cards_pl_deck[i].next = NULL;

			//**************************************************************PRZETWARZANIE PLIKU
			while (1) //pêtla powtarzaj¹ca siê a¿ do przeanalizowania kart "przed graczem"(deck cards) ostatniego gracza
			{
				list1* place_hand;
				list1* place_deck;
				fscanf(file1, "%s", word);

				int number = atoi(word);
				place_hand = cards_on_hand + (number - 1);
				place_deck = cards_pl_deck + (number - 1);

				char hand_deck[5];

				if (fgets(line, SIZE - 1, file1) != NULL)
				{
					for (int i = 8; i < 12; i++)
						hand_deck[i - 8] = line[i];
					hand_deck[4] = '\0';

					if (number == pl_num) 
					{
						if (see_if_hand_deck(hand_deck) == 'h')
						{
							token = strtok(line + 19, " \n");			//od miejsca 19 bêd¹ siê znajdowa³y interesuj¹ce nas dane
							find_colors(number_of_colors, token);
							place_hand = segregate_pile_hand_deck(token, place_hand);
							place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);

							while (token != NULL)
							{
								players_handx2[number]++;
								token = strtok(NULL, " \n");
								find_colors(number_of_colors, token);
								place_hand = segregate_pile_hand_deck(token, place_hand);
								place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);

							}
						}
						else if (see_if_hand_deck(hand_deck) == 'd')
						{
							token = strtok(line + 19, " \n");
							find_colors(number_of_colors, token);
							place_deck = segregate_pile_hand_deck(token, place_deck);
							place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
							while (token != NULL)
							{
								players_deckx2[number]++;
								token = strtok(NULL, " \n");
								find_colors(number_of_colors, token);
								place_deck = segregate_pile_hand_deck(token, place_deck);
								place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
							}
							break;		//wiemy, ¿e bêd¹ to ostatnie sprawdzane karty przed graczem i koñczymy sprawdzanie kart przed graczem i na rêku
						}
					}
					else
					{
						if (see_if_hand_deck(hand_deck) == 'h')
						{
							token = strtok(line + 19, " \n");
							find_colors(number_of_colors, token);
							place_hand = segregate_pile_hand_deck(token, place_hand);
							place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
							while (token != NULL)
							{
								players_handx2[number]++;
								token = strtok(NULL, " \n");
								find_colors(number_of_colors, token);
								place_hand = segregate_pile_hand_deck(token, place_hand);
								place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
							}
						}
						else if (see_if_hand_deck(hand_deck) == 'd')
						{
							token = strtok(line + 19, " \n");
							find_colors(number_of_colors, token);
							place_deck = segregate_pile_hand_deck(token, place_deck);
							place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
							while (token != NULL)
							{
								players_deckx2[number]++;
								token = strtok(NULL, " \n");
								find_colors(number_of_colors, token);
								place_deck = segregate_pile_hand_deck(token, place_deck);
								place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
							}
						}
					}
				}
			}

			//**************************************************************STOSY KART*********************************************************************************//

			//**************************************************************ZMIENNE
			int number_of_piles;
			number_of_piles = count_colors(number_of_colors);
			int cards_in_pilex2[7] = { 0 };
			list1* pile_cards;
			pile_cards = new list1[number_of_piles];
			for (int i = 0; i < number_of_piles; i++)
				pile_cards[i].next = NULL;
			//**************************************************************PRZETWARZANIE PLIKU
			while (1)			//pêtla powtarzaj¹ca siê a¿ do przeanalizoania ostatniego stosu kart
			{
				int pile_number = 0;
				list1* place_pile;

				fscanf(file1, "%d", &pile_number);
				place_pile = pile_cards + (pile_number - 1);

				if (fgets(line, SIZE - 1, file1) != NULL)
				{
					if (pile_number == number_of_piles)
					{
						token = strtok(line + 12, " \n");		//od miejsca 12 bêd¹ siê znajdowa³y interesuj¹ce nas dane
						place_pile = segregate_pile_hand_deck(token, place_pile);
						place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
						while (token != NULL)
						{
							cards_in_pilex2[pile_number]++;
							token = strtok(NULL, " \n");
							place_pile = segregate_pile_hand_deck(token, place_pile);
							place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
						}
						break;			//wiemy, ¿e bêdzie to oststni sprawdzany stos, wiêc przerywamy pêtlê
					}
					else
					{
						token = strtok(line + 12, " \n");
						if (token != "0")
						{
							place_pile = segregate_pile_hand_deck(token, place_pile);
							place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
						}
						while (token != NULL)
						{
							cards_in_pilex2[pile_number]++;
							token = strtok(NULL, " \n");
							if (token != "0")
							{
								place_pile = segregate_pile_hand_deck(token, place_pile);
								place_in_cnntd_vc = segregate_cards(token, cnntd_vc, place_in_cnntd_vc);
							}
						}
					}
				}
			}
			fclose(file1);
			//**************************************************************SPRAWDZANIE STANU GRY 2*********************************************************************************//
			cout << "-------------------------------------->>GAME STATUS<<--------------------------------------" << endl;

			int game_state[3] = { 0 };
			int g = 0, blu = 0, r = 0, v = 0, y = 0, w = 0, blck = 0;
			card1 green_cards[CARDS], blue_cards[CARDS], red_cards[CARDS], violet_cards[CARDS], yellow_cards[CARDS], white_cards[CARDS], black_cards[CARDS];

			count_cards_hdp(pl_num, players_handx2, players_deckx2, number_of_piles, cards_in_pilex2);
			counting_cards(g, blu, r, v, y, w, blck, place_in_cnntd_vc, cnntd_vc);
			segregare_card_colors(g, blu, r, v, y, w, blck, green_cards, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards, place_in_cnntd_vc, cnntd_vc);
			number_of_cards(blu, r, v, y, w, blck);
			compare_arrays(blu, r, v, y, w, blck, blue_cards, red_cards, violet_cards, yellow_cards, white_cards, black_cards);
			check_game_state(players_handx2, ac_pl, place_in_cnntd_vc, pl_num, pile_cards, number_of_piles, cards_in_pilex2, expl);

			//**************************************************************RUCH LUB KONIEC RUNDY*********************************************************************************//
			int end_of_game = 0;
			for (int k = 0; k <= pl_num; k++)
				end_of_game += players_handx2[k];
			if (end_of_game == 0)
			{
				cout << "-------------------------------------->>>>END OF ROUND "<<round_nr <<"<<<<--------------------------------------" << endl;
				end_the_game(cards_pl_deck, pl_num, player_points, round_nr);
				break;
			}
			else
			{
				cout << "-------------------------------------->>NEXT PLAYER<<--------------------------------------" << endl;
				eazy_move(cards_on_hand + (ac_pl - 1), pile_cards, cards_pl_deck + (ac_pl - 1), number_of_piles, expl);
				print_game_status(ac_pl, pl_num, expl, cards_on_hand, cards_pl_deck, pile_cards, number_of_piles);

				file1 = fopen("plik.txt", "w");
				fprint_game_status(file1, ac_pl, pl_num, expl, cards_on_hand, cards_pl_deck, pile_cards, number_of_piles);
				fclose(file1);
			}
			delete[] players_handx2;
			players_handx2 = NULL;
			delete[] players_deckx2;
			players_deckx2 = NULL;
			delete_hdp(cards_on_hand, pl_num);
			delete_hdp(cards_pl_deck, pl_num);
			delete_hdp(pile_cards, number_of_piles);
		}
		round_nr++;
	}

	//**************************************************************PODLICZENIE KOÑCA GRY*********************************************************************************//
	the_final_countdown( player_points, n);
	return 0;
}