/**
 *  Examples of flags that could be set
 * */
enum humanActorFlags
{
    HUM_ACTOR_DEFAULT = 0x00,
    HUM_ACTOR_DEAD = 0x01,
    HUM_ACTOR_INJURED = 0x02,
    HUM_ACTOR_SLEEPING = 0x04,
    HUM_ACTOR_AGGRO = 0x08,
    HUM_ACTOR_SCARED = 0x10
};

inline humanActorFlags operator |(humanActorFlags a, humanActorFlags b) {
	return static_cast<humanActorFlags>(static_cast<int>(a) | static_cast<int>(b));
}

inline humanActorFlags operator |=(humanActorFlags a, humanActorFlags b) {
	return a = a | b;
}

inline humanActorFlags operator &(humanActorFlags a, humanActorFlags b) {
	return static_cast<humanActorFlags>(static_cast<int>(a) & static_cast<int>(b));
}

inline humanActorFlags operator ~(humanActorFlags a) {
	return static_cast<humanActorFlags>(~static_cast<int>(a));
}