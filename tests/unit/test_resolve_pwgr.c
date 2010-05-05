#include "misc.h"

int main(void)
{
  uid_t uid;
  gid_t gid;

  if (!resolve_user("root", &uid))
    return 1;

  if (!resolve_user("0", &uid) || uid != 0)
    return 1;

  if (!resolve_user("-1", &uid) || uid != -1)
    return 1;

  if (resolve_group("nincsily", &gid))
    return 1;

  if (!resolve_group("0", &gid) || gid != 0)
    return 1;

  if (!resolve_group("-1", &gid) || gid != -1)
    return 1;

  if (!resolve_group("daemon", &gid))
    return 1;

  if (resolve_group("nincsily", &gid))
    return 1;
  return 0;
}
