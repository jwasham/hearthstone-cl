# hearthstone-cl

An experimental command-line Hearthstone simulator in C++

Good starting point reference of all cards:
https://github.com/pdyck/hearthstone-db/blob/master/cards/all-cards.json

Card list on Hearthhead:
http://www.hearthhead.com/cards#text:0+2-12-11

---

Quick Start (for now, during initial development):

1. Clone the project.
2. cd to project directory.
3. Build it like this:


    g++ -std=c++11 main.cpp HearthstoneGame.cpp -o hearthstone_cl
    ./hearthstone_cl -D --strict-deck=false deck1.txt deck2.txt


Alternately, you can use `cmake` if you know the commands.

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

- properties
    - name
    - hero (Hero class)
    - deck (Deck class)
    - hand (Hand class)
    - board half
    - mana
    - graveyard (hidden)

#### Deck

- properties
    - CARD_MAX = 30 (for initialization)
    - hero class
    - Cards cards[] (or vector. Some effects can make deck size grow well beyond CARD_MAX)
- methods
    - addCard(Card & card)
    - shuffle()
    - getRandomCards(int count) // for initial hand
    - canDrawCard()
    - drawCard()
    - shuffleIntoDeck(Card & card)

#### Hero (Character)

- properties
    - name
    - health
    - armor
    - HeroClass
- methods
    - usePower()
    - canUsePower()
    - canAttack()

#### HeroClass

- properties
    - name
    - heroPower

#### HeroPower

- properties
    - cost
- methods
    - canUse();
    - use(Entity & entity);

#### HeroClasses

- methods
    - getHeroFromClassName()

#### Card

- properties
    - name
    - cost
- methods
    - canPlayCard()
    - virtual play()

#### Minion (Card)

- properties
    - name
    - cost
    - attack
    - health
    - battlecry
    - charge
    - taunt
    - stealth
    - targetable
- methods
    - play()

#### Spell (Card)

- properties
    - name
    - cost
    - text
- methods
    - play()
    
#### Minion (Character)

- properties
    - name
    - cost
    - attack
    - health
    - battlecry
    - charge
    - taunt
    - stealth
    - targetable
- methods
    - battleCry()
    - hasCharge()
    - hasTaunt()
    - canAttack()
    - attack()
    - takeDamage(int damage)
    - die() - on destroy or health <= 0
    - remove() - non-death removal

#### Hand

- properties
    - Card cards[]
- method
    - canPlayACard()

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
- card played
- battlecry
- summon
- minion being attacked
- on damaged
- on destroyed
- hero power played
- hero attacks
- minion attacks
- fatigue taken

