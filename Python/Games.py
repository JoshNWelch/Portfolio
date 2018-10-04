'''
-----------------------------------------------------
File: Games.py

This program adds Divers game to our existing menu,
that welcomes the Professor Falken. Then asks how the
user is feeling, asks the user if they want to play a
game. Prompts the user with 7 options
the 4 working games are a number guessing game, Tic-Tac-Toe,
Blackjack, and Divers and then tells the user goodbye.

Written by: Josh Welch
Date: September 7, 2018

-----------------------------------------------------
'''

#-----------------------Imports---------------------------
import random
import os
#----------------------Constants-------------------------
CARD = '23456789TJQKA'
SUIT = 'DHCS'

#----------------- Function Definitions -----------------

'''
Funtion: welcome( )
Inputs: None
Outputs: prints to the screen "Welcome Professor Falken"
Returns: None

Funtion: feel( )
Inputs: None
Outputs: prints to the screen "How do you feel?"
Returns: Variable feeling containing a string

Funtion: game( )
Inputs: None
Outputs: prints to the screen "Shall we play a game?"
         Then prints a few options a few options for
         the user to select.
Returns: Variable number containing a integer

Funtion: goodbye( )
Inputs:  integer
Outputs: prints to the screen "The only winning move
         for that game (#) is not to play"
Returns: None

Funtion: number_guess_game( )
Inputs:  None
Outputs: Prompts the user to pick a number and tries guessing the number based on
         the user's input of higher or lower
Returns: None

Funtion: draw_board( )
Inputs:  Takes in 9 variables representing spots on the board.
Outputs: Prints to the screen the current state of the board based on the variables inputted
Returns: None

Funtion: validate( )
Inputs:  Takes in 10 variables representing spots on the board and the space the user/program is trying to play on.
Outputs: None
Returns: A string variable containing the word "valid" or "invalid".

Funtion: game_over( )
Inputs:  Takes in 10 variables representing spots on the board and the user's symbol
Outputs: Checks to see if the user/program won, then
         prints to the screen "The symbol of which charter wins!"
Returns: 1 if there was a win 0 if no win.

Funtion: tic_tac_toe( )
Inputs:  None
Outputs: Prints to the screen for the user to choose X or O and displays instructions
         how to play and draws the game board. Then loops through the player and the 
         program placing their symbols until someone wins or there is no more plays
         left, then displays "Game Over" and returns.
Returns: None

Funtion: draw_card( )
Inputs:  string - used_cards
Outputs: Takes in used_cards, randomly chooses a new card, compares that to used_cards
         if the card is in used_cards it chooses another one until it picks a card that
         isn't in used_cards. Then returns the chosen card.
Returns: string - card

Funtion: card_value( )
Inputs:  string - hand
Outputs: Takes in a hand of cards, loops through the hand adding the values up and checks for
         Ace's. It will change the Ace's value based on the car_total. Then returns the total.
Returns: int - card_total

Funtion: check_bust( )
Inputs:  int - card_total
Outputs: Takes in the card_total, then checks if the value is greater than 21. If greater
         returns True, otherwise False.
Returns: Boolean

Funtion: check_win( )
Inputs:  user_hand, user_total, dealer_hand, dealer_total
Outputs: Takes in both players hands and card totals. First it checks the number of cards
         if the player has 5 cards and the dealer has less than 5 cards the player wins.
         then checks if the dealer has 5 cards if so the dealer wins. Next it checks if 
         both players have the same total if so the dealer wins. Finally checks if the
         player's total is greater than the dealer if so the player wins else the dealer
         wins. All of these if statements will print who wins and then return.
Returns: None

Funtion: blackjack( )
Inputs:  None
Outputs: Deals the player and dealer 2 cards, prints both the players cards but only prints
         one of the dealers cards. Then asks the user if they want to hit or stay while
         checking if the player busts. Then both of the dealer cards are revealed the dealer
         will continue to draw cards until his hand is greater than 17 while checking if the
         dealer busts. It will then check to see who wins then print to the screen.
Returns: None

Funtion: make_grid( )
Inputs:  Optional input for number of rows/columns default is 6
Outputs: Creates a list of lists(table) with number of rows=columns
Returns: table

Funtion: set_computer_divers( )
Inputs:  table, number of divers default is 3
Outputs: Randomly places 3 divers on the table and checks to make sure it is not placing
         2 divers on the same place
Returns: table

Funtion: set_player_divers( )
Inputs:  table, number of divers default is 3
Outputs: Asks the user to input a row and column for each diver, then makes sure the space
         is available to be placed on ensuring only 1 diver per space.
Returns: table

Funtion: print_grid( )
Inputs:  table
Outputs: Loops through the List of Lists printing the table to the screen.
Returns: None

Funtion: player_guess( )
Inputs:  guess_table, computer_table
Outputs: Asks the user to enter a row and column to guess where the computer placed it's divers.
         The function then checks the space and updates the guess table with an * if a diver is
         found or an O if no diver is found. The program also checks and makes sure the player
         hasn't guessed the same place before. Then returns the updated guess table.
Returns: table

Funtion: computer_guess( )
Inputs:  player_table
Outputs: The computer randomly chooses a row and column to guess while making sure it doesn't
         guess the same place twice. The function then updates the players table depending if
         a diver was found or not.
Returns: table

Funtion: remaining_divers( )
Inputs:  table
Outputs: Looks through the table and returns the number of remaining divers.
Returns: int - number of divers remaining

Funtion: divers( )
Inputs:  None
Outputs: Main function that calls make grid 3 times(guess_table, player_table, computer_table)
         Places divers on the computer_table and player_table. Randomly chooses who goes first
         Player and Computer make guesses at each other one after another. After each guess
         the remaining_divers function is called and if remaining divers = 0 then the game
         says who won then exits the game.
Returns: None


'''

def welcome( ):
    print('Welcome Professor Falken')

def feel( ):
    feeling = input('How do you feel? ')
    print('I feel excellent! -program')
    return feeling

def goodbye(game_number = ' '):
    if (game_number == ' '):
        print('Goodbye Professor Falken')
    else:
        print('The only winning move for that game (', \
        game_number,') is not to play.')
        print('Goodbye Professor Falken')

def game( ):
    ans = input('Shall we play a game? ')
    if (ans == 'no' or ans =='NO' or ans == 'No' or ans == 'n' or ans == 'N'):
        goodbye()
        return "No"
    
    print('I Want to play a game. -computer')
    print("1. Guess Your Number \n2. Tic-Tac-Toe\
         \n3. Black Jack \n4. Falken's Maze {Under Construction}\
         \n5. Divers! \n6. Global Thermonuclear War {Under Construction}\
         \n7. Exit without playing a game.")
    number = int(input('Select a number: '))
    return number

def number_guess_game():
    print('Pick a number from 1 through 10, I will guess the number in less than 4 trys.')
    high = int(10)
    low = int(1)
    check = 'n'
    print('Enter h if my guess is to high, enter l if my guess is to low, and enter w if my guess is correct.')
    while(check!='w'):
        choices = int(high - low + 1)
        guess = int(choices/2 + low)
        print('Is your number:',guess)
        check = input()
        if (check == 'h'):
            high = guess - 1
        elif (check == 'l'):
            low = guess + 1
    print('I Win!')

##############################TICTACTOE################################
def draw_board(SP1, SP2, SP3, SP4, SP5, SP6, SP7, SP8, SP9):
    print(SP1,'|',SP2,'|',SP3)
    print('__|___|__')
    print(SP4,'|',SP5,'|',SP6)
    print('__|___|__')
    print(SP7,'|',SP8,'|',SP9)
    print('  |   |  ')
    
def validate(play, sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9):
    play = int(play)
    if (play == 1 and sp1 == ' '):
        return 'valid'
    elif (play == 2 and sp2 == ' '):
        return 'valid'
    elif (play == 3 and sp3 == ' '):
        return 'valid'
    elif (play == 4 and sp4 == ' '):
        return 'valid'
    elif (play == 5 and sp5 == ' '):
        return 'valid'
    elif (play == 6 and sp6 == ' '):
        return 'valid'
    elif (play == 7 and sp7 == ' '):
        return 'valid'
    elif (play == 8 and sp8 == ' '):
        return 'valid'
    elif (play == 9 and sp9 == ' '):
        return 'valid'
    else:
        return 'invalid'

def game_over(token, sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9):
    if (sp1 != ' ' and sp1 == sp2 and sp1 == sp3):
        print('Player', token, 'Wins!')
        return 1
    elif (sp4 != ' ' and sp4 == sp5 and sp4 == sp6):
        print('Player', token, 'Wins!')
        return 1
    elif (sp7 != ' ' and sp7 == sp8 and sp7 == sp9):
        print('Player', token, 'Wins!')
        return 1
    elif (sp1 != ' ' and sp1 == sp4 and sp1 == sp7):
        print('Player', token, 'Wins!')
        return 1
    elif (sp2 != ' ' and sp2 == sp5 and sp3 == sp8):
        print('Player', token, 'Wins!')
        return 1
    elif (sp3 != ' ' and sp3 == sp6 and sp3 == sp9):
        print('Player', token, 'Wins!')
        return 1
    elif (sp1 != ' ' and sp1 == sp5 and sp1 == sp9):
        print('Player', token, 'Wins!')
        return 1
    elif (sp3 != ' ' and sp3 == sp5 and sp3 == sp7):
        print('Player', token, 'Wins!')
        return 1
    else:
        return 0
        
def tic_tac_toe():
    symbol = input('Enter what symbol you would like to play as X or O: ')
    if (symbol == 'X' or symbol == 'x'):
        ai = 'O'
    else:
        ai = 'X'
    print('Use the following board as a guide for where each number plays on the board.')
    print('1','|','2','|','3')
    print('__|___|__')
    print('4','|','5','|','6')
    print('__|___|__')
    print('7','|','8','|','9')
    print('  |   |  ')
    sp1 = ' '
    sp2 = ' '
    sp3 = ' '
    sp4 = ' '
    sp5 = ' '
    sp6 = ' '
    sp7 = ' '
    sp8 = ' '
    sp9 = ' '
    space = 'invalid'
    print('Current board state: ')
    draw_board(sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9)
    
    for i in range(5):
        
        while(space == 'invalid'):
            play = input('Enter the number of the space you would like to play: ')
            space = validate(play, sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9)
        play = int(play)
        
        if (play == 1):
            sp1 = symbol
        elif (play == 2):
            sp2 = symbol
        elif (play == 3):
            sp3 = symbol
        elif (play == 4):
            sp4 = symbol
        elif (play == 5):
            sp5 = symbol
        elif (play == 6):
            sp6 = symbol
        elif (play == 6):
            sp6 = symbol
        elif (play == 7):
            sp7 = symbol
        elif (play == 8):
            sp8 = symbol
        else:
            sp9 = symbol

        print('Current board state: ')
        draw_board(sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9)
        space ='invalid'
        if (game_over(symbol, sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9) == 1):
            print('Game Over!')
            return
        if (i==4):
            print('Game Over!')
            return
        
        while(space == 'invalid'):
            play = random.randint(1,10)
            space = validate(play, sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9)        

        if (play == 1):
            sp1 = ai
        elif (play == 2):
            sp2 = ai
        elif (play == 3):
            sp3 = ai
        elif (play == 4):
            sp4 = ai
        elif (play == 5):
            sp5 = ai
        elif (play == 6):
            sp6 = ai
        elif (play == 6):
            sp6 = ai
        elif (play == 7):
            sp7 = ai
        elif (play == 8):
            sp8 = ai
        else:
            sp9 = ai

        space = 'invalid'
        print('Current board state: ')
        draw_board(sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9)
        if(game_over(ai, sp1, sp2, sp3, sp4, sp5, sp6, sp7, sp8, sp9) == 1):
            print('Game Over!')
            return
############################BLACKJACK###########################
def draw_card(used_cards):
    chosen_card = True
    while (chosen_card):
        num = random.choice(CARD)
        suit = random.choice(SUIT)
        card = num + suit
        if card not in used_cards:
            return card

def card_value(hand):
    card_total = 0
    for i in range(1,len(hand),3):
        if hand[i] in 'TJQK':
            card_total += 10
        elif hand[i] == 'A':
            card_total += 11
        else:
            card_total += CARD.find(str(hand[i])) + 2
    for card in hand:
     if (card_total > 21 and card == 'A'):
         card_total -= 10
    return card_total

def check_bust(card_total):
    if (card_total > 21):
        return True
    else:
        return False

def check_win(user_hand, user_total, dealer_hand, dealer_total):
    if (len(user_hand) >= 14 and len(dealer_hand) < 14):
        print('Player Wins!')
        return
    if (len(dealer_hand) >= 14):
        print('Dealer Wins!')
        return
    if (user_total == dealer_total):
        print('Dealer Wins!')
        return
    elif (user_total > dealer_total):
        print('Player Wins!')
        return
    else:
        print('Dealer Wins!')
        return

def blackjack():
    user_card = ''
    user_hand = ''
    user_card_total = 0
    computer_card = ''
    computer_hand = ''
    computer_card_total = 0
    used_cards = ''
    play = True
    player_bust = False
    dealer_bust = False

    print('BLACKJACK')
    print('Enter h to Hit')
    print('Enter s to Stay \n')

    computer_card = draw_card(used_cards)
    used_cards += computer_card
    computer_hand += ' ' + computer_card
    computer_card_total = card_value(computer_hand)

    print('Dealer Hand: ', computer_hand, ' ?? \n')

    computer_card = draw_card(used_cards)
    used_cards += computer_card
    computer_hand += ' ' + computer_card
    computer_card_total = card_value(computer_hand)

    user_card = draw_card(used_cards)
    used_cards += user_card
    user_hand += ' ' + user_card
    user_card_total = card_value(user_hand)
    user_card = draw_card(used_cards)
    used_cards += user_card
    user_hand += ' ' + user_card
    user_card_total = card_value(user_hand)

    print('Player Hand: ', user_hand)
    print('Card Total Value = ',user_card_total)

    while (play):
        user = input('Hit or Stay? ')
        if (user.lower() == 'h'):
            user_card = draw_card(used_cards)
            used_cards += user_card
            user_hand += ' ' + user_card
            user_card_total = card_value(user_hand)
            print('User Hand: ', user_hand)
            print('Card Total Value = ',user_card_total)
            print()
            if(check_bust(user_card_total)):
                play = False
                player_bust = True
        else:
            play = False

    if(player_bust):
        play = False
        print('Player bust, Dealer Wins!')
    else:
        play = True
        print()
        print('Dealer Hand: ', computer_hand)
        print('Card Total Value = ',computer_card_total)
        print()

    while (play):
        if (computer_card_total < 17):
            computer_card = draw_card(used_cards)
            used_cards += computer_card
            computer_hand += ' ' + computer_card
            computer_card_total = card_value(computer_hand)
            print('Dealer Hand: ', computer_hand)
            print('Card Total Value = ',computer_card_total)
            print()
            if(check_bust(computer_card_total)):
                play = False
                dealer_bust = True
        else:
            play = False

        if (len(computer_hand) >= 14):
            play = False

    if(dealer_bust):
        print('Dealer bust, Player Wins!')
    else:
        check_win(user_hand, user_card_total, computer_hand, computer_card_total)

#########################DIVERS########################
def make_grid(num_rows_cols = 6):
    table = []
    row = []
    for rows in range (num_rows_cols):
        for col in range (num_rows_cols):
            row.append('-')
        table.append(row)
        row = []    #gives new memory location
    return table

def set_computer_divers(table, num_divers = 3):
    while(num_divers > 0):
        row = random.randint(0,(len(table)-1))
        col = random.randint(0,(len(table)-1))
        if (table[row][col] == '-'):
            table[row][col] = 'X'
            num_divers -= 1
    return table

def set_player_divers(table, num_divers = 3):
    print('You have 3 divers to place')
    while(num_divers > 0):
        row = int(input('Enter the row for diver: '))
        col = int(input('Enter the column for diver: '))
        if (table[row][col] == '-'):
            table[row][col] = 'X'
            num_divers -= 1
        else:
            print('Invalid placement')
    return table

def print_grid(table):
    for row in table:
        print(row)

def player_guess(table_guess, table_computer):
    while(True):
        row = int(input('Enter the row you would like to guess: '))
        col = int(input('Enter the column you would like to guess: '))
        if (table_computer[row][col]== '-' and table_guess[row][col] == '-'):
            table_guess[row][col] = 'O'
            return table_guess
        elif (table_computer[row][col]== 'X' and table_guess[row][col] == '-'):
            table_guess[row][col] = '*'
            return table_guess
        else:
            print('Invalid placement')

def computer_guess(table):
    while(True):
        row = random.randint(0,(len(table)-1))
        col = random.randint(0,(len(table)-1))
        if (table[row][col]== '-'):
            table[row][col] = 'O'
            print('Computer Guessed: grid[', row, '][', col,']')
            return table
        elif (table[row][col]== 'X'):
            table[row][col] = '*'
            print('Computer Guessed: grid[', row, '][', col,']')
            return table

def remaining_divers(table):
    divers = 3
    for row in table:
        divers -=row.count('*')
    return divers



def divers():
    print()
    print('        DIVERS!')
    print()
    player_board = make_grid()
    computer_board = make_grid()
    guess_board = make_grid()
    player_board = set_player_divers(player_board)
    compuer_board = set_computer_divers(computer_board)
    os.system('cls')
    random_start = random.randint(0,1)
    play = True

    if (random_start == 0):
        print('Player Goes First')
        input('Press Enter to Start')
        while(play):
            os.system('cls')
            print('Number of Player Divers remaining:', remaining_divers(player_board))
            print('Number of Computer Divers remaining:', remaining_divers(guess_board))
            print()
            print('Guess Board:')
            print_grid(guess_board)
            print()
            print('Player Board:')
            print_grid(player_board)
            guess_board = player_guess(guess_board, computer_board)

            if (remaining_divers(guess_board) == 0):
                print('Player Wins!')
                play=False
            else:
                player_board = computer_guess(player_board)

            if (remaining_divers(player_board) == 0):
                print('Computer Wins!')
                play=False
    else:
        print('Computer Goes First')
        input('Press Enter to Start')
        while(play):
            os.system('cls')
            player_board = computer_guess(player_board)
            print('Number of Player Divers remaining:', remaining_divers(player_board))
            print('Number of Computer Divers remaining:', remaining_divers(guess_board))
            print()

            if (remaining_divers(player_board) == 0):
                print('Computer Wins!')
                play=False
            else:
                print('Guess Board:')
                print_grid(guess_board)
                print()
                print('Player Board:')
                print_grid(player_board)
                guess_board = player_guess(guess_board, computer_board)
                
            if (remaining_divers(guess_board) == 0):
                print('Player Wins!')
                play=False

#----------------------Main Code------------------------
welcome()
how_are_you = feel()
sel = 0
while(sel!= 7 and sel!='No'):
    sel = game()
    if (sel == 1):
        number_guess_game()
    elif (sel == 2):
        tic_tac_toe()
    elif (sel == 3):
        blackjack()
    elif (sel == 5):
        divers()
    elif (sel == 6):
        goodbye(sel)
    elif (sel == 7):
        goodbye()
