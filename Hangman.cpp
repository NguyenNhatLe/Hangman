#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

string chooseWord();
string initWord(int l);
char getPlayerGuess();
bool contains(vector<char> word, char guess);
string render(string word, vector<char> k);

void drawGallows(int bad);

int main() {
	srand(time(0));
	string secretWord = chooseWord();
	string guessWord = initWord(secretWord.length());
	vector<char> selectedChar;
	int  badGuessCount = 0;

	cout << "This word has " << secretWord.length() << " characters" << endl;
	do {
		char c = getPlayerGuess();

		if (secretWord.find(c) < secretWord.length() && !contains(selectedChar, c)) {
			cout << "Congrat! Its true guess!" << endl;
			selectedChar.push_back(c);
			guessWord = render(secretWord, selectedChar);

		}
		else {
			cout << "Oh no! It doesnt has this character!" << endl;
			badGuessCount++;
			selectedChar.push_back(c);
		}
		cout << "Your currWord is : " << guessWord << endl;
		cout << "Number of wrong guess: " << badGuessCount << "/7" << endl;

		drawGallows(badGuessCount);
		cout << endl;
	} while (badGuessCount < 7 && guessWord != secretWord);

	if (badGuessCount == 7) {
		cout << "You lost. The correct word is " << secretWord;
	}
	if (guessWord == secretWord) {
		cout << "Congratulations! You win!";
	}
}

string chooseWord() {
	string WORD_LIST[] = {
"angle", "ant", "apple", "arch", "arm", "army",
"baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
  "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
"brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
"cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
"chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
"cow", "cup", "curtain", "cushion",
"dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
"face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
"foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm", };

	int len = sizeof(WORD_LIST) / sizeof(string);
	int random = rand() % len;
	return WORD_LIST[random - 1];
}

string initWord(int l) {
	string tmp = "";
	for (int i = 0; i < l; i++) {
		tmp += "_ ";
	}
	return tmp;
}

char getPlayerGuess() {
	char c;
	cout << "Enter your guess: ";
	cin >> c;
	cout << endl;
	return c;
}

bool contains(vector<char> word, char guess) {
	if (find(word.begin(), word.end(), guess) != word.end()) {
		return true;
	}
	else {
		return false;
	}
}

string render(string word, vector<char> k) {
	string tmp = "";

	for (int i = 0; i < word.length(); i++) {
		char s = word[i];
		if (contains(k, s)) {
			string str = "" + s + ' ';
			tmp += s;

		}
		else {
			tmp += "_ ";

		}
	}
	return tmp;
}

void drawGallows(int badGuessCount) {
	for (int i = 0; i < 14; i++) {
		cout << endl;
	}
	string fig7 = "  ______________    \n"
		"  |             |   \n"
		"  |             O   \n"
		"  |            /|\\  \n"
		"  |            / \\  \n"
		"  |                 \n"
		"  |                 \n"
		"__|__               ";
	string fig6 = "  ______________    \n"
		"  |             |   \n"
		"  |             O   \n"
		"  |            /|\\  \n"
		"  |            /   \n"
		"  |                 \n"
		"  |                 \n"
		"__|__               ";
	string fig5 = "  ______________    \n"
		"  |             |   \n"
		"  |             O   \n"
		"  |            /|\\  \n"
		"  |                 \n"
		"  |                 \n"
		"  |                 \n"
		"__|__               ";
	string fig4 = "  ______________    \n"
		"  |             |   \n"
		"  |             O   \n"
		"  |            /|  \n"
		"  |                \n"
		"  |                 \n"
		"  |                 \n"
		"__|__               ";
	string fig3 = "  ______________    \n"
		"  |             |   \n"
		"  |             O   \n"
		"  |             |  \n"
		"  |                 \n"
		"  |                 \n"
		"  |                 \n"
		"__|__               ";
	string fig2 = "  ______________    \n"
		"  |             |   \n"
		"  |             O   \n"
		"  |                 \n"
		"  |                \n"
		"  |                 \n"
		"  |                 \n"
		"__|__               ";
	string fig1 = "  ______________    \n"
		"  |             |   \n"
		"  |                \n"
		"  |                \n"
		"  |                \n"
		"  |                 \n"
		"  |                 \n"
		"__|__               ";
	string fig0 = "  ______________    \n"
		"  |                 \n"
		"  |                 \n"
		"  |                 \n"
		"  |                 \n"
		"  |                 \n"
		"  |                 \n"
		"__|__               ";

	const string FIGURE[] = { fig0, fig1, fig2, fig3, fig4, fig5, fig6, fig7 };
	cout << FIGURE[badGuessCount] << endl;
}




