#include "transformrect.h"

QRect transformRect(QRect& rect, double dx, double dy)
{
    return QRect(rect.x() * dx, rect.y() * dy, rect.width() * dx, rect.height() * dy);
}
