using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;

class CodeEval102{
	static void Main(){
		string str;
		for(;(str=Console.ReadLine())!=null;){
			var serializer = new DataContractJsonSerializer(typeof(Data));
			Data data = (Data)serializer.ReadObject(new MemoryStream(Encoding.Unicode.GetBytes(str)));
			int ret=0;
			foreach(Data.Item item in data.menu.items){
				if(item!=null && item.label!=null)ret+=item.id;
			}
			Console.WriteLine(ret);
		}
	}
}

[DataContract]
public class Data
{
	[DataContract]
	public class Item
	{
		[DataMember]
		public int id { get; set; }
		[DataMember]
		public string label { get; set; }
	}
	[DataContract]
	public class Menu
	{
		[DataMember]
		public string header { get; set; }
		[DataMember]
		public List<Item> items { get; set; }
	}
	[DataMember]
	public Menu menu { get; set; }
}