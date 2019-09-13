#ifndef CONFIG_EXTRUDER_CONTROL_H
#define CONFIG_EXTRUDER_CONTROL_H

// ##########################################################################################
// ##                           Extruder control                                           ##
// ##########################################################################################


/* \brief Minimum temperature for extruder operation

This is a safety value. If your extruder temperature is below this temperature, no
extruder steps are executed. This is to prevent your extruder to move unless the filament
is at least molten. After having some complains that the extruder does not work, I leave
it 0 as default.
*/

#define MIN_EXTRUDER_TEMP 160

/** \brief Enable advance algorithm.

Without a correct adjusted advance algorithm, you get blobs at points, where acceleration changes. The
effect increases with speed and acceleration difference. Using the advance method decreases this effect.
For more informations, read the wiki.
*/
#define USE_ADVANCE 1

/** \brief enables quadratic component.

Set 1 to allow, 0 disallow a quadratic advance dependency. Linear is the dominant value, so no real need
to activate the quadratic term. Only adds lots of computations and storage usage. */
#define ENABLE_QUADRATIC_ADVANCE 0

#endif
