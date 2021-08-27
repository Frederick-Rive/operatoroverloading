#include <iostream>
#include <vector>

class YoutubeChannel
{
private:
	int subCount;
	std::string name;
public:
	YoutubeChannel(std::string n, int subs)
	{
		name = n;
		subCount = subs;
	}

	int subs()
	{
		return subCount;
	}

	std::string channelName()
	{
		return name;
	}

	bool operator!= (YoutubeChannel rhs)
	{
		return (this->name != rhs.name && this->subCount != rhs.subCount) ? true : false;
	}

	bool operator== (YoutubeChannel rhs)
	{
		return (this->name == rhs.name && this->subCount == rhs.subCount) ? true : false;
	}
};

struct ChannelCollection
{
	std::vector<YoutubeChannel> channels;

	void operator+= (YoutubeChannel rhs)
	{
		this->channels.push_back(rhs);
	}

	void operator-= (YoutubeChannel rhs)
	{
		std::vector<YoutubeChannel> tempChannels;
		for (int i = 0; i < channels.size(); i++)
		{
			if (channels[i] != rhs)
			{
				tempChannels.push_back(channels[i]);
			}
		}

		channels = tempChannels;
	}
};

std::ostream& operator<<(std::ostream& cOUT, YoutubeChannel yc)
{
	cOUT << "Name: " << yc.channelName() << " | Subs: " << yc.subs();
	return cOUT;
}

int main()
{
	YoutubeChannel yc1 = YoutubeChannel("wow", 3444343);
	YoutubeChannel yc2 = YoutubeChannel("yeah", 423765);
	YoutubeChannel yc3 = YoutubeChannel("crazy", 5454554);

	ChannelCollection myCollection;
	myCollection += yc1;
	myCollection += yc2;
	myCollection += yc3;

	for (int i = 0; i < 3; i++)
	{
		std::cout << myCollection.channels[i] << std::endl;
	}

	myCollection -= yc1;

	for (int i = 0; i < 2; i++)
	{
		std::cout << myCollection.channels[i] << std::endl;
	}
}
