#pragma region MARIO 

//
//BIG MARIO
//

#define ID_SPRITE_MARIO 10000
#define ID_SPRITE_MARIO_BIG (ID_SPRITE_MARIO + 1000)
#define ID_SPRITE_MARIO_BIG_IDLE (ID_SPRITE_MARIO_BIG + 100)
#define ID_SPRITE_MARIO_BIG_IDLE_LEFT (ID_SPRITE_MARIO_BIG_IDLE + 10)
#define ID_SPRITE_MARIO_BIG_IDLE_RIGHT (ID_SPRITE_MARIO_BIG_IDLE + 20)

#define ID_SPRITE_MARIO_BIG_WALKING (ID_SPRITE_MARIO_BIG + 200)
#define ID_SPRITE_MARIO_BIG_WALKING_LEFT (ID_SPRITE_MARIO_BIG_WALKING + 10)
#define ID_SPRITE_MARIO_BIG_WALKING_RIGHT (ID_SPRITE_MARIO_BIG_WALKING + 20)
#define ID_SPRITE_MARIO_BIG_RUNNING (ID_SPRITE_MARIO_BIG + 300)
#define ID_SPRITE_MARIO_BIG_RUNNING_LEFT (ID_SPRITE_MARIO_BIG_RUNNING + 10)
#define ID_SPRITE_MARIO_BIG_RUNNING_RIGHT (ID_SPRITE_MARIO_BIG_RUNNING + 20)
#define ID_SPRITE_MARIO_BIG_JUMP (ID_SPRITE_MARIO_BIG + 400)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK (ID_SPRITE_MARIO_BIG_JUMP + 10)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_LEFT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_BIG_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN (ID_SPRITE_MARIO_BIG_JUMP + 20)
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_LEFT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 2) //11422
#define ID_SPRITE_MARIO_BIG_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 6)
#define ID_SPRITE_MARIO_BIG_JUMP_MAX_SPEED_RIGHT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 30) //11451
#define ID_SPRITE_MARIO_BIG_JUMP_MAX_SPEED_LEFT (ID_SPRITE_MARIO_BIG_JUMP_RUN + 20)
#define ID_SPRITE_MARIO_BIG_SIT (ID_SPRITE_MARIO_BIG + 500)
#define ID_SPRITE_MARIO_BIG_SIT_LEFT (ID_SPRITE_MARIO_BIG_SIT + 10)
#define ID_SPRITE_MARIO_BIG_SIT_RIGHT (ID_SPRITE_MARIO_BIG_SIT + 20)
#define ID_SPRITE_MARIO_BIG_BRACE (ID_SPRITE_MARIO_BIG + 600)
#define ID_SPRITE_MARIO_BIG_BRACE_LEFT (ID_SPRITE_MARIO_BIG_BRACE + 10)
#define ID_SPRITE_MARIO_BIG_BRACE_RIGHT (ID_SPRITE_MARIO_BIG_BRACE + 20)
#define ID_SPRITE_MARIO_BIG_KICK (ID_SPRITE_MARIO_BIG + 700)
#define ID_SPRITE_MARIO_BIG_KICK_LEFT (ID_SPRITE_MARIO_BIG_KICK + 10) 
#define ID_SPRITE_MARIO_BIG_KICK_RIGHT (ID_SPRITE_MARIO_BIG_KICK + 20)
#define ID_SPRITE_MARIO_BIG_HOLDING (ID_SPRITE_MARIO_BIG + 800)
#define ID_SPRITE_MARIO_BIG_HOLDING_LEFT (ID_SPRITE_MARIO_BIG_HOLDING + 10) 
#define ID_SPRITE_MARIO_BIG_HOLDING_RIGHT (ID_SPRITE_MARIO_BIG_HOLDING + 20)
#define ID_SPRITE_MARIO_BIG_HOLDING_WALKING (ID_SPRITE_MARIO_BIG + 900)
#define ID_SPRITE_MARIO_BIG_HOLDING_LEFT (ID_SPRITE_MARIO_BIG_HOLDING_WALKING + 10) 
#define ID_SPRITE_MARIO_BIG_HOLDING_RIGHT (ID_SPRITE_MARIO_BIG_HOLDING_WALKING + 20)

#define ID_SPRITE_MARIO_DIE (ID_SPRITE_MARIO + 3000)

//
//SMALL MARIO
//

#define ID_SPRITE_MARIO_SMALL (ID_SPRITE_MARIO + 2000)
#define ID_SPRITE_MARIO_SMALL_IDLE (ID_SPRITE_MARIO_SMALL + 100)
#define ID_SPRITE_MARIO_SMALL_IDLE_LEFT (ID_SPRITE_MARIO_SMALL_IDLE + 10)
#define ID_SPRITE_MARIO_SMALL_IDLE_RIGHT (ID_SPRITE_MARIO_SMALL_IDLE + 20)

#define ID_SPRITE_MARIO_SMALL_WALKING (ID_SPRITE_MARIO_SMALL + 200)
#define ID_SPRITE_MARIO_SMALL_WALKING_LEFT (ID_SPRITE_MARIO_SMALL_WALKING + 10)
#define ID_SPRITE_MARIO_SMALL_WALKING_RIGHT (ID_SPRITE_MARIO_SMALL_WALKING + 20)
#define ID_SPRITE_MARIO_SMALL_RUNNING (ID_SPRITE_MARIO_SMALL + 300)
#define ID_SPRITE_MARIO_SMALL_RUNNING_LEFT (ID_SPRITE_MARIO_SMALL_RUNNING + 10)
#define ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT (ID_SPRITE_MARIO_SMALL_RUNNING + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP (ID_SPRITE_MARIO_SMALL + 400)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK (ID_SPRITE_MARIO_SMALL_JUMP + 10)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN (ID_SPRITE_MARIO_SMALL_JUMP + 20)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_SMALL_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 6)
#define ID_SPRITE_MARIO_SMALL_JUMP_MAX_SPEED_RIGHT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 30) //12451
#define ID_SPRITE_MARIO_SMALL_JUMP_MAX_SPEED_LEFT (ID_SPRITE_MARIO_SMALL_JUMP_RUN + 20)
#define ID_SPRITE_MARIO_SMALL_KICK_LEFT (ID_SPRITE_MARIO_SMALL_IDLE_LEFT + 15)
#define ID_SPRITE_MARIO_SMALL_KICK_RIGHT (ID_SPRITE_MARIO_SMALL_IDLE_RIGHT + 15)
#define ID_SPRITE_MARIO_SMALL_BRACE (ID_SPRITE_MARIO_SMALL + 500)
#define ID_SPRITE_MARIO_SMALL_BRACE_LEFT (ID_SPRITE_MARIO_SMALL_BRACE + 10)
#define ID_SPRITE_MARIO_SMALL_BRACE_RIGHT (ID_SPRITE_MARIO_SMALL_BRACE + 20)
#define ID_SPRITE_MARIO_SMALL_HOLD (ID_SPRITE_MARIO_SMALL + 600)
#define ID_SPRITE_MARIO_SMALL_HOLD_LEFT (ID_SPRITE_MARIO_SMALL_HOLD + 10)
#define ID_SPRITE_MARIO_SMALL_HOLD_RIGHT (ID_SPRITE_MARIO_SMALL_HOLD + 20)
#define ID_SPRITE_MARIO_SMALL_HOLD_WALK_LEFT (ID_SPRITE_MARIO_SMALL_HOLD + 30)
#define ID_SPRITE_MARIO_SMALL_HOLD_WALK_RIGHT (ID_SPRITE_MARIO_SMALL_HOLD + 40)

//
//RACOON MARIO
//

#define ID_SPRITE_MARIO_RACOON (ID_SPRITE_MARIO + 4000)
#define ID_SPRITE_MARIO_RACOON_IDLE (ID_SPRITE_MARIO_RACOON + 100)
#define ID_SPRITE_MARIO_RACOON_IDLE_LEFT (ID_SPRITE_MARIO_RACOON_IDLE + 10)
#define ID_SPRITE_MARIO_RACOON_IDLE_RIGHT (ID_SPRITE_MARIO_RACOON_IDLE + 20)
#define ID_SPRITE_MARIO_RACOON_WALKING (ID_SPRITE_MARIO_RACOON + 200)
#define ID_SPRITE_MARIO_RACOON_WALKING_LEFT (ID_SPRITE_MARIO_RACOON_WALKING + 10)
#define ID_SPRITE_MARIO_RACOON_WALKING_RIGHT (ID_SPRITE_MARIO_RACOON_WALKING + 20)
#define ID_SPRITE_MARIO_RACOON_RUNNING (ID_SPRITE_MARIO_RACOON + 300)
#define ID_SPRITE_MARIO_RACOON_RUNNING_LEFT (ID_SPRITE_MARIO_RACOON_RUNNING + 10)
#define ID_SPRITE_MARIO_RACOON_RUNNING_RIGHT (ID_SPRITE_MARIO_RACOON_RUNNING + 20)
#define ID_SPRITE_MARIO_RACOON_JUMP (ID_SPRITE_MARIO_RACOON + 400)
#define ID_SPRITE_MARIO_RACOON_JUMP_WALK (ID_SPRITE_MARIO_RACOON_JUMP + 10)
#define ID_SPRITE_MARIO_RACOON_JUMP_WALK_LEFT (ID_SPRITE_MARIO_RACOON_JUMP_WALK + 2)
#define ID_SPRITE_MARIO_RACOON_JUMP_WALK_RIGHT (ID_SPRITE_MARIO_RACOON_JUMP_WALK + 6)
#define ID_SPRITE_MARIO_RACOON_JUMP_RUN (ID_SPRITE_MARIO_RACOON_JUMP + 20)
#define ID_SPRITE_MARIO_RACOON_JUMP_RUN_LEFT (ID_SPRITE_MARIO_RACOON_JUMP_RUN + 2)
#define ID_SPRITE_MARIO_RACOON_JUMP_RUN_RIGHT (ID_SPRITE_MARIO_RACOON_JUMP_RUN + 6)
#define ID_SPRITE_MARIO_RACOON_JUMP_MAX_SPEED_RIGHT (ID_SPRITE_MARIO_RACOON_JUMP_RUN + 30) //14451
#define ID_SPRITE_MARIO_RACOON_JUMP_MAX_SPEED_LEFT (ID_SPRITE_MARIO_RACOON_JUMP_RUN + 20)

#define ID_SPRITE_MARIO_RACOON_BRACE (ID_SPRITE_MARIO_RACOON + 500)
#define ID_SPRITE_MARIO_RACOON_BRACE_LEFT (ID_SPRITE_MARIO_RACOON_BRACE + 10)
#define ID_SPRITE_MARIO_RACOON_BRACE_RIGHT (ID_SPRITE_MARIO_RACOON_BRACE + 20)

#define ID_SPRITE_MARIO_RACOON_SIT (ID_SPRITE_MARIO_RACOON + 600)
#define ID_SPRITE_MARIO_RACOON_SIT_LEFT (ID_SPRITE_MARIO_RACOON_SIT + 10)
#define ID_SPRITE_MARIO_RACOON_SIT_RIGHT (ID_SPRITE_MARIO_RACOON_SIT + 20)
#define ID_SPRITE_MARIO_RACOON_KICK (ID_SPRITE_MARIO_RACOON + 700)
#define ID_SPRITE_MARIO_RACOON_KICK_LEFT (ID_SPRITE_MARIO_RACOON_KICK + 10)
#define ID_SPRITE_MARIO_RACOON_KICK_RIGHT (ID_SPRITE_MARIO_RACOON_KICK + 20)
#define ID_SPRITE_MARIO_RACOON_ATTACK (ID_SPRITE_MARIO_RACOON + 800)
#define ID_SPRITE_MARIO_RACOON_ATTACK_LEFT (ID_SPRITE_MARIO_RACOON_ATTACK + 10)
#define ID_SPRITE_MARIO_RACOON_ATTACK_RIGHT (ID_SPRITE_MARIO_RACOON_ATTACK + 20)
#define ID_SPRITE_MARIO_RACOON_FALL (ID_SPRITE_MARIO_RACOON + 900)
#define ID_SPRITE_MARIO_RACOON_FALL_LEFT (ID_SPRITE_MARIO_RACOON_FALL + 10)
#define ID_SPRITE_MARIO_RACOON_FALL_RIGHT (ID_SPRITE_MARIO_RACOON_FALL + 20)
#define ID_SPRITE_MARIO_RACOON_FLY (ID_SPRITE_MARIO_RACOON + 1000)
#define ID_SPRITE_MARIO_RACOON_FLY_LEFT (ID_SPRITE_MARIO_RACOON_FLY + 10)
#define ID_SPRITE_MARIO_RACOON_FLY_RIGHT (ID_SPRITE_MARIO_RACOON_FALL + 20)
#define ID_SPRITE_MARIO_RACOON_LANDING (ID_SPRITE_MARIO_RACOON + 1100)
#define ID_SPRITE_MARIO_RACOON_LANDING_LEFT (ID_SPRITE_MARIO_RACOON_LANDING + 10) //
#define ID_SPRITE_MARIO_RACOON_LANDING_RIGHT (ID_SPRITE_MARIO_RACOON_LANDING + 20) 

#pragma endregion #pragma once
