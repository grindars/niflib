/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIGEOMMORPHERCONTROLLER_H_
#define _NIGEOMMORPHERCONTROLLER_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "NiInterpController.h"

// Include structures
#include "../Ref.h"
#include "../gen/MorphWeight.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiMorphData;
class NiInterpolator;
class NiGeomMorpherController;
typedef Ref<NiGeomMorpherController> NiGeomMorpherControllerRef;

/*! Time controller for geometry morphing. */
class NiGeomMorpherController : public NiInterpController {
public:
	/*! Constructor */
	NIFLIB_API NiGeomMorpherController();

	/*! Destructor */
	NIFLIB_API virtual ~NiGeomMorpherController();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//

	//TODO: Lots of unknown data in this object

	/*!
	 * This function will adjust the times in all the keys in the data objects
	 * referenced by this controller and any of its interpolators such that the
	 * phase will equal 0 and frequency will equal one.  In other words, it
	 * will cause the key times to be in seconds starting from zero.
	 */
	NIFLIB_API virtual void NormalizeKeys();

	/*!
	 * Retrives a list of the interpolators used by this controller.
	 * \return The interpolators.
	 */
	NIFLIB_API vector< Ref<NiInterpolator> > GetInterpolators() const;

	/*!
	 * Sets the list of the interpolators used by this controller.
	 * \param[in] n The new interpolators.
	 */
	NIFLIB_API void SetInterpolators( const vector< Ref<NiInterpolator> > & n );

	/*!
	 * Retrives the morph data used by this controller.
	 * \return The morph data.
	 */
	NIFLIB_API Ref<NiMorphData> GetData() const;

	/*!
	 * Sets the morph data used by this controller.
	 * \param[in] n The new morph data.
	 */
	NIFLIB_API void SetData( NiMorphData * n );

	/*!
	* Update the Model Bounds
	*/
	NIFLIB_API void UpdateModelBound();

	//--END CUSTOM CODE--//
protected:
	/*! Unknown. */
	unsigned short extraFlags;
	/*! Unknown. */
	byte unknown2;
	/*! Geometry morphing data index. */
	Ref<NiMorphData > data;
	/*! Always Update */
	byte alwaysUpdate;
	/*! The number of interpolator objects. */
	mutable unsigned int numInterpolators;
	/*! List of interpolators. */
	vector<Ref<NiInterpolator > > interpolators;
	/*! Weighted Interpolators? */
	vector<MorphWeight > interpolatorWeights;
	/*! A count. */
	mutable unsigned int numUnknownInts;
	/*! Unknown. */
	vector<unsigned int > unknownInts;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//
//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
