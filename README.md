# hearthstone-cl

An experimental command-line Hearthstone simulator in C++

Good starting point reference of all cards:
https://github.com/pdyck/hearthstone-db/blob/master/cards/all-cards.json

Card list on Hearthhead:
http://www.hearthhead.com/cards#text:0+2-12-11

---

Usage:

    NAME
        hearthstone_cl - a command-line Hearthstone game
    
    SYNOPSIS
        hearthstone_cl [-D] [--strict-deck=false] deck1.txt deck2.txt
        (deck files go in "decks" directory)
    
    OPTIONS
        -D = debug mode
        --strict-deck=false = allow any deck of 30 cards, no restrictions
        --strict-deck=true = (default) legal deck of 30 cards

---

## Plan

### Objects:

#### Game

#### Player

- name
- class
- hero
- hero power
- deck
- hand
- board half
- mana
- graveyard (hidden)

#### Play Log

#### Board

### Flow:

- pre-game
    - get player names
    - deck check:
        - read deck files:
            - class
            - card list
        - cards exist
        - cards ok for player's class
        - no more than one of each legendary
        - no more than 2 of each other card
        - card count = 30 cards
- start game
    - greetings
    - coin flip
        - one player gets 3 cards, goes first, no coin
        - other player gets 4 cards + coin, goes second
    - deck shuffle
    - initial hand
    - mulligan
    - if mulligan:
        - get and show replacement cards from remaining deck
        - shuffle deck
- turn
    - player switch
    - mana refresh
    - mana + 1 if mana < max_mana
    - auto **card draw**
    - **turn begins trigger**
    - play card?
    - hero power?
    - attack?
    - end turn
    - **turn ends trigger**
- card draw
    - card draw trigger
    - anything that affects card draw on turn?
    - pop 1 card from deck
    - fatigue?
    - **add to hand**
- add to hand
    - hand + 1 card
    - check hand space, hand size <= max_hand_size
    - if > max_hand_size, burn card

### Events:

- turn begins
- card draw
- add to hand
- turn ends
