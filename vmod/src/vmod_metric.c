#include <stdlib.h>
#include <stdio.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"

#include "vcc_if.h"

int init_function(struct vmod_priv *priv, const struct VCL_conf *conf)
{
	return 0;
}

unsigned vmod_match(struct sess *sp, const char *username, const char *password)
{
	return 0;
}
