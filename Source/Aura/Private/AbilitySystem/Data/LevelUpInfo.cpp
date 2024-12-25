// Copyright huner


#include "AbilitySystem/Data/LevelUpInfo.h"

int32 ULevelUpInfo::FindLevelForXP(int32 XP) const
{
	int32 level = 1;
	bool bSearch = true;
	while (bSearch)
	{
		if (LevelUpInformation.Num()-1 <=level)	return level;

		if (XP>=LevelUpInformation[level].LevelUpRequirement)
		{
			++level;
		}
		else
		{
			bSearch = false;
		}
	}
	return level;
}
