# Non-Destructive FilletEdge Plugin (Current Implementation)
This is a show-case page for my work at LBP. Due to company policies, the plugin is currently private.

## Overview

This Rhino3d C++ plugin is a partial reimplementation of the FilletEdge command with a focus on non-destructive visualization(not working yet).
Instead of modifying the original BRep geometry directly, the command will:
- Compute filleted copies of selected edges
- Store them in a temporary state some how
- Displays them as a live preview overlay
- (Optionally replaces the original geometry at the end of the command)
For now it is an early-stage prototype of a destructive fillet edge workflow

---

## Key Features (for now)

### Edge-Based Fillet Selection
- Users select BRep edges directly
- Selections from ,=multiple BReps and multiple edges per BRep are supported
- Edges are saved per source BRep
### Configurable Command Options
The command supports interactive options, including
- configurable radius -> numeric input
- ShowRadius -> toggle (enables/disables conduit)
- Preview -> toggle (enables/disables conduit)
- RailType -> fillet computation mode
  - DistFromEdge
  - RollingBall
  - DistBetweenRails
- BlendTupe -> fillet computation mode
  - Chamfer
  - Fillet
  - Blend
### Live Preview
A custom display conduit: CFilletPreviewConduit, provides:
- preview display of filleted BReps in wireframe / shaded mode
- Optional UI overlay text showing "Radius = xxx" state
- Real-time updates when RailType or BlendType changes

---

##  Command Execution Flow
The command is structured as a finite state machine: State Breakdown:
- State_Basic
  - Object selection
  - Radius + preview option handling
  - Initial edge capture
- State_Advanced
  - Rail type selection
  - Additional option toggles
  - Optional preview refresh
- State_Compute
  - Calls Rhino fillet API
  - Builds final filleted Breps
  - Handles failures per-object
- State_Redraw
  -Deletes original objects (if applicable)
  -Inserts filleted geometry into document
  - Disables preview conduit
  - Forces redraw

---

## Core Data Structures

### FilletItem
It holds:
- Selected Breps and Objs
- Index of selected edges per BRep
- Result of Filleting
- Which fillets succeeded
### FilletEdgeOptValue
It stores user-configurable settings:
- radius
- showRadius
- preview
- railType
- blendType
### FilletRuntime: 
Stores runtime command state:

---

## Known Limitations (Current Stage)
- No temporary storage (no UserData yet)
- Fillets are not non-destructively bound to original geometry
- No variable radius fillets yet

---

## Next Planned Steps 
- Store fillets in object UserData
- Persist across file saves (.3dm support)
- Override object drawing instead of replacing geometry
- Detect transforms and rebuild fillets
- Support variable radius fillets
- Add chamfers and blends
- Improve sub-object mapping after edits

---

# End of Document