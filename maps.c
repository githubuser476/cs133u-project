#include "./headers/maps.h"

//local protytypes



static room * _current_room;        //this points to current room

room * get_current_room(){
    //interface to get room
    return _current_room;
}

int set_current_room(room * curroom){
    //interface to set room
    _current_room = curroom;
    return 1;
}

int pickup_item(){
    //grab player reference
   gamepiece * player = get_player();
   
   //grab x, y coords
   int x = get_piece_x(player);
   int y = get_piece_y(player);
    
    gamepiece * item = grab_item_reference(x, y);                        //pick up the item 
        
    if(item != NULL){
        piecetype type = get_piece_type(item);                          //grab the type
    
        if( (type == SWORD_TYPE) || (type == SHIELD_TYPE) ){             //only for sword and shield for now
            gamepiece * tmp_item = equip_item_to_player(player, item);   //equip item and grab pointer to formerly equipped item
            
            if(remove_item_from_map(item) != 0){
                printf("couldn't remove item from map\n");
                return 1;
            }
            if(tmp_item != NULL){
                set_piece_x(tmp_item, x);                                //copy coords to item being dropped
                set_piece_y(tmp_item, y);
                add_item_to_map(tmp_item);
            }
            
            //construct and add message to queue
            char message[40];                                    
            strncat(message, "Equipped: ", 11);
            strncat(message, get_piece_name(item), 20);
            add_message_queue(message);
        }
    }
    return 0;
}

int remove_item_from_map(gamepiece * item){
    int x = get_piece_x(item);
    int y = get_piece_y(item);
    
    for(int i = 0; i < 5; i++){
        gamepiece * temp = _current_room->bounty[i];
        if( temp != NULL){
            int it_x = get_piece_x(temp);
            int it_y = get_piece_y(temp);
            
            if( (it_x == x) && (it_y == y) ){
                _current_room->bounty[i] = NULL;
                return 0;
            }
        }
    }
    return 1;
}

int add_item_to_map(gamepiece * item){
    int x = get_piece_x(item);
    int y = get_piece_y(item);
    
    for(int i = 0; i < 5; i++){
        if(_current_room->bounty[i] == NULL){
            _current_room->bounty[i] = item;   //look for empty slot to add item
            return 0;
        }
    }
    return 1;
}

gamepiece * grab_item_reference(int x, int y){
    //look for item at x,y and return pointer, leave in bounty list
    for(int i = 0; i < 5; i++){
        gamepiece * temp = _current_room->bounty[i];
        if( temp != NULL){
            int it_x = get_piece_x(temp);
            int it_y = get_piece_y(temp);
            
            if( (it_x == x) && (it_y == y) ){
                return temp;
            }
        }
    }
    return NULL;
}

gamepiece * get_player(){
    //super quick interface
    return _current_room->monsters[0];
}
