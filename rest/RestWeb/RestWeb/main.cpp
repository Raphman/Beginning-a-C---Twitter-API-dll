#include "twitterAPI.h"
using namespace System;
using namespace System::Net;
using namespace std;
using namespace System::Text;
using namespace System::IO;
using namespace System::Xml;





void TwitterAPI::GetStatus()
{
	string usr;
	cout << "enter a name" << endl;
	getline(cin,usr);
	String^ username = gcnew String(usr.c_str());
	String^ uri ="https://api.twitter.com/1/statuses/user_timeline.xml?include_entities=true&include_rts=true&screen_name=";
	String^ request = uri + username;
	try
	{

	
	HttpWebRequest^ myReq = dynamic_cast<HttpWebRequest^>(WebRequest::Create( request ));
	myReq->Method = "GET";
	myReq->ServicePoint->Expect100Continue = false; 
	myReq->ContentType="application/x-www-form-urlencoded";
	HttpWebResponse^ HttpWResp = dynamic_cast<HttpWebResponse^>(myReq->GetResponse());
	Stream^ myStream = HttpWResp->GetResponseStream();
	Encoding^ encode = System::Text::Encoding::GetEncoding( "utf-8" );
	StreamReader^ readStream = gcnew StreamReader(myStream,encode);
	String^ resString = readStream->ReadToEnd();
	StringBuilder^ output = gcnew StringBuilder();
	String^ result;
	XmlReader^ reader = XmlReader::Create(gcnew StringReader(resString));
	if(reader->ReadToFollowing("text"))
		output->AppendLine(reader->ReadElementContentAsString());
	if (reader->ReadToFollowing("name"))
	{
		output->AppendLine(reader->ReadElementContentAsString());
	}
	result = output->ToString();
	Console::Write(result);
	 
	HttpWResp->Close();
	myStream->Close();
	}
	catch (WebException^ ex)
	{
		Console::WriteLine("Something went wrong, either a 404 or a 401 ( unauthorized)");
	}
	cout<< "DONE" <<endl;
}