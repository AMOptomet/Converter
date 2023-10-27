/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkAffineRepresentation.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkAffineRepresentation - abstract class for representing affine transformation widgets
// .SECTION Description
// This class defines an API for affine transformation widget
// representations. These representations interact with vtkAffineWidget. The
// basic functionality of the affine representation is to maintain a
// transformation matrix.
//
// This class may be subclassed so that alternative representations can
// be created.  The class defines an API and a default implementation that
// the vtkAffineWidget interacts with to render itself in the scene.

// .SECTION Caveats
// The separation of the widget event handling and representation enables
// users and developers to create new appearances for the widget. It also
// facilitates parallel processing, where the client application handles
// events, and remote representations of the widget are slaves to the
// client (and do not handle events).

// .SECTION See Also
// vtkAffineWidget vtkWidgetRepresentation vtkAbstractWidget


#ifndef __vtkAffineRepresentation_h
#define __vtkAffineRepresentation_h

#include "vtkInteractionWidgetsModule.h" // For export macro
#include "vtkWidgetRepresentation.h"

class vtkTransform;

class VTKINTERACTIONWIDGETS_EXPORT vtkAffineRepresentation : public vtkWidgetRepresentation
{
public:
  // Description:
  // Standard methods for instances of this class.
  vtkTypeMacro(vtkAffineRepresentation,vtkWidgetRepresentation);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Retrieve a linear transform characterizing the affine transformation
  // generated by this widget. This method copies its internal transform into
  // the transform provided. The transform is relative to the initial placement
  // of the representation (i.e., when PlaceWidget() is invoked).
  virtual void GetTransform(vtkTransform *t) = 0;

  // Description:
  // The tolerance representing the distance to the widget (in pixels)
  // in which the cursor is considered near enough to the widget to
  // be active.
  vtkSetClampMacro(Tolerance,int,1,100);
  vtkGetMacro(Tolerance,int);

//BTX
  // Enums define the state of the representation relative to the mouse pointer
  // position. Used by ComputeInteractionState() to communicate with the
  // widget.
  enum _InteractionState
  {
    Outside=0, Rotate, Translate, TranslateX, TranslateY, ScaleWEdge, ScaleEEdge,
    ScaleNEdge, ScaleSEdge, ScaleNE, ScaleSW, ScaleNW, ScaleSE,
    ShearEEdge, ShearWEdge, ShearNEdge, ShearSEdge,
    MoveOriginX, MoveOriginY, MoveOrigin
  };
//ETX

  // Description:
  // Methods to make this class properly act like a vtkWidgetRepresentation.
  virtual void ShallowCopy(vtkProp *prop);

protected:
  vtkAffineRepresentation();
  ~vtkAffineRepresentation();

  // The tolerance for selecting different parts of the widget.
  int Tolerance;

  // The internal transformation matrix
  vtkTransform *Transform;

private:
  vtkAffineRepresentation(const vtkAffineRepresentation&);  //Not implemented
  void operator=(const vtkAffineRepresentation&);  //Not implemented
};

#endif
