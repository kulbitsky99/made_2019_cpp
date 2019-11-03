class Loader
{
	using Onloaded = void (*)(const char* data, size_t size)
	void load(const std::string& uri, Onloaded callback)
	{
		auto connection = openConnection(uri);
		std::async([]()
				{
					while(connection)
						connection.read(data);
					callback(data, size);	
				});
	}
};

void RenderFile(const char * data, size_t size)
{
	XmlReader xml(data, size);
	HtmlReadered r;
	Page page;
	r.render(xml);
}
	
Loader loader;
loader.load("ya.ru", RenderFile);
//PlayMusic();
//rapid gsong
