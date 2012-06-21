backend local {
	.host = "127.0.0.1";
	.port = "3000";
}

sub vcl_recv {
	set req.http.x-host = req.http.host;
	set req.http.x-url  = req.url;
	set req.http.host   = regsub (req.http.host, "^www\.", "");
}