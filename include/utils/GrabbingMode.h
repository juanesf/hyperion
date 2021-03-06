#pragma once

/**
 * Enumeration of the possible modes in which frame-grabbing is performed.
 */
enum GrabbingMode
{
    /** Frame grabbing is switched off */
    GRABBINGMODE_OFF,
    GRABBINGMODE_VIDEO,
    GRABBINGMODE_PHOTO,
    GRABBINGMODE_AUDIO,
    GRABBINGMODE_MENU,
    GRABBINGMODE_SCREENSAVER
};
