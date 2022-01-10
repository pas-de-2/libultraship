#pragma once

#include "OTRResource.h"

namespace OtrLib
{
	enum class LimbType
	{
		Invalid,
		Standard,
		LOD,
		Skin,
		Curve,
		Legacy,
	};

	enum class ZLimbSkinType
	{
		SkinType_0,           // Segment = 0
		SkinType_4 = 4,       // Segment = segmented address // Struct_800A5E28
		SkinType_5 = 5,       // Segment = 0
		SkinType_DList = 11,  // Segment = DList address
	};

	class OTRSkeletonLimbV0 : public OTRResourceFile
	{
	public:
		void ParseFileBinary(BinaryReader* reader, OTRResource* res) override;
	};

	class Struct_800A57C0
	{
	public:
		uint16_t unk_0;
		int16_t unk_2;
		int16_t unk_4;
		int8_t unk_6;
		int8_t unk_7;
		int8_t unk_8;
		uint8_t unk_9;
	};

	class Struct_800A598C_2
	{
	public:
		uint8_t unk_0;
		int16_t x;
		int16_t y;
		int16_t z;
		uint8_t unk_8;
	};

	class Struct_800A598C
	{
	public:
		uint16_t unk_0;  // Length of unk_8
		uint16_t unk_2;  // Length of unk_C
		uint16_t unk_4;  // 0 or 1 // Used as an index for unk_C

		std::vector<Struct_800A57C0> unk_8_arr;
		std::vector<Struct_800A598C_2> unk_C_arr;
	};

	class OTRSkeletonLimb : public OTRResource
	{
	public:
		LimbType limbType;
		
		ZLimbSkinType skinSegmentType;
		uint16_t skinVtxCnt;
		std::vector<Struct_800A598C> skinData;

		float legTransX, legTransY, legTransZ;  // Vec3f
		uint16_t rotX, rotY, rotZ;              // Vec3s

		std::string childPtr, siblingPtr, dListPtr, dList2Ptr;

		int16_t transX, transY, transZ;
		uint8_t childIndex, siblingIndex;

	};
}