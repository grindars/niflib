/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiSphericalCollider.h"

//Definition of TYPE constant
const Type NiSphericalCollider::TYPE("NiSphericalCollider", &NI_SPHERICAL_COLLIDER_PARENT::TYPE );

NiSphericalCollider::NiSphericalCollider() NI_SPHERICAL_COLLIDER_CONSTRUCT {}

NiSphericalCollider::~NiSphericalCollider() {}

void NiSphericalCollider::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	NI_SPHERICAL_COLLIDER_READ
}

void NiSphericalCollider::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_SPHERICAL_COLLIDER_WRITE
}

string NiSphericalCollider::asString( bool verbose ) const {
	NI_SPHERICAL_COLLIDER_STRING
}

void NiSphericalCollider::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	NI_SPHERICAL_COLLIDER_FIXLINKS
}
