//Evan Sinasac - 1081418
//INFO6046 Media Fundamentals (Project 1)
//main.cpp description:
//				For Project 1, our objective is to show our understanding of the GLFW and FMOD libraries to play
//				and modify several different sounds.  The sounds will be loaded from an external file so they can
//				be changed without recompiling the application.  Likely this program will become it's own file/set of files
//				to handle playing sounds during game play

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <FMOD/fmod.hpp>

#include <rssgl/GLText.h>

#include <vector>

//Globals
GLuint _windowWidth = 1024;
GLuint _windowHeight = 720;

GLFWwindow* _window = NULL;
std::string _appName = "Project 1";

FMOD::System* _system = NULL;
FMOD_RESULT _result = FMOD_OK;

std::vector<FMOD::Sound*> _sounds;
FMOD::Channel* _channel = NULL;

RSS::GLText* _text;
GLuint _textRowIndex = 2;

bool _isPaused = false;
float volume = 0.f;
float pitch = 0.f;
float wet = 0.f;
bool isMuted = false;
bool wantToRamp = true;

std::vector<std::string> songNames;

//Callback
static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Close the window when the user presses ESC
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	} 
	//Keys 1 through 0 and SPACE play the 11 various sounds we've loaded
	//Error checking here to make sure we don't try to reference a sound that hasn't been loaded 
	//i.e. if there were only 5 audio files, only keys 1-5 should work
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		if (0 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[0], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		if (1 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[1], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_3 && action == GLFW_PRESS)
	{
		if (2 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[2], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_4 && action == GLFW_PRESS)
	{
		if (3 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[3], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_5 && action == GLFW_PRESS)
	{
		if (4 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[4], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_6 && action == GLFW_PRESS)
	{
		if (5 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[5], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_7 && action == GLFW_PRESS)
	{
		if (6 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[6], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_8 && action == GLFW_PRESS)
	{
		if (7 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[7], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_9 && action == GLFW_PRESS)
	{
		if (8 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[8], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_0 && action == GLFW_PRESS)
	{
		if (9 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[9], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		if (10 < _sounds.size())
		{
			if (_isPaused)
			{
				_isPaused = false;
			}
			if (_channel)
			{
				_channel->stop();	//keeps the program only playing one sound at a time
			}
			_result = _system->playSound(_sounds[10], 0, false, &_channel);
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to play sound");
			}
		}
	}
	//Pressing the TAB key will pause the application
	if (key == GLFW_KEY_TAB && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_result = _channel->getPaused(&_isPaused);
			_result = _channel->setPaused(!_isPaused);
			_result = _channel->getPaused(&_isPaused);
		}
	} //end of TAB
	//Pressing P will raise the volume
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_channel->getVolume(&volume);
			if (volume >= 5.f)
				volume += 5.f;
			else if (volume >= 1.f)
				volume++;
			else
				volume += 0.1f;
			_result = _channel->setVolume(volume);
		}
	} //pressing O will lower the volume
	else if (key == GLFW_KEY_O && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_channel->getVolume(&volume);
			if (volume > 5.f)
				volume -= 5.f;
			else if (volume <= 0.f)
				volume = 0.f;
			else if (volume > 1.f)
				volume--;
			else
				volume -= 0.1f;
			_result = _channel->setVolume(volume);
		}
	}
	//Pressing L will raise the pitch
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_channel->getPitch(&pitch);
			pitch += 0.1f;
			if (pitch >= 2.f)
				pitch = 2.f;
			_result = _channel->setPitch(pitch);
		}
	} //pressing K will lower the volume
	else if (key == GLFW_KEY_K && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_channel->getPitch(&pitch);
			pitch -= 0.1f;
			if (pitch <= 0.f)
				pitch = 0.f;
			_result = _channel->setPitch(pitch);
		}
	}
	//Pressing M will raise the reverb
	if (key == GLFW_KEY_M && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_channel->getReverbProperties(1, &wet);
			wet += 0.1f;
			if (wet >= 1.f)
				wet = 1.f;
			_result = _channel->setReverbProperties(1, wet);
		}
	} //pressing keypad / will lower the volume
	else if (key == GLFW_KEY_N && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_channel->getReverbProperties(1, &wet);
			wet -= 0.1;;
			if (wet <= 0.f)
				wet = 0.f;
			_result = _channel->setReverbProperties(1, wet);
		}
	}
	//Mute
	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_result = _channel->getMute(&isMuted);
			_result = _channel->setMute(!isMuted);
			_result = _channel->getMute(&isMuted);
		}
	}
	//Volume Ramp
	if (key == GLFW_KEY_Z && action == GLFW_PRESS)
	{
		if (_channel)
		{
			_result = _channel->getVolumeRamp(&wantToRamp);
			_result = _channel->setVolumeRamp(!wantToRamp);
			_result = _channel->getVolumeRamp(&wantToRamp);
		}
	}

} //end of glfw_key_callback

void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "FMOD Error(%d): %s", error, description);
} //end of glfw_error_callback

//Function Signatures
bool init();
bool initGLFW();
bool initGL();
bool initFMOD();
void shutdown();

bool loadSounds();

int main(int argc, char* argv)
{
	if (!init())
	{
		fprintf(stderr, "Unable to initialize app");
		exit(EXIT_FAILURE);
	}

	_text->addLine("Hello!  Welcome to this simple sound board!", _textRowIndex++);

	GLuint lastKnownRowIndex = _textRowIndex;

	FMOD::Sound* currentSound = nullptr;
	GLuint currentSoundLengthInMS = 0;

	

	//Main loop
	while (!glfwWindowShouldClose(_window))
	{
		glClearColor(0.2f, 0.2f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		lastKnownRowIndex = _textRowIndex;
		std::stringstream ss;

		//Go through the songs that were loaded and print them to the screen with the assigned buttons
		for (unsigned int index = 0; index < _sounds.size(); index++)
		{
			if (index < 9)
			{
				ss << "Press key " << (index+1) << " to play: " << songNames[index];
				_text->addLine(ss.str(), lastKnownRowIndex++);
			}
			else if (index == 9)
			{
				ss << "Press key 0 to play: " << songNames[index];
				_text->addLine(ss.str(), lastKnownRowIndex++);
			}
			else if (index == 10)
			{
				ss << "Press space to play: " << songNames[index];
				_text->addLine(ss.str(), lastKnownRowIndex++);
			}
			else
			{
				ss << "You also added: " << songNames[index];
				_text->addLine(ss.str(), lastKnownRowIndex++);
			}
			ss.str("");
		} //end for

		//is sound paused
		ss << "Is channel paused: " << ((_isPaused) ? "Yes" : "No");
		_text->addLine(ss.str(), lastKnownRowIndex++);
		ss.str("");

		//Get the actual length of current sound
		if (_channel)
		{
			_channel->getCurrentSound(&currentSound);
			if (currentSound)
			{
				_result = currentSound->getLength(&currentSoundLengthInMS, FMOD_TIMEUNIT_MS);
			}
		}
		ss << "Current sound length in MS: " << currentSoundLengthInMS;
		_text->addLine(ss.str(), lastKnownRowIndex++);
		ss.str("");

		//Get the current volume level 
		if (_channel)
		{
			_channel->getVolume(&volume);
		}
		ss << "Current volume level is (press P to increase, O to decrease): " << volume;
		_text->addLine(ss.str(), lastKnownRowIndex++);
		ss.str("");

		//Get the current pitch
		if (_channel)
		{
			_channel->getPitch(&pitch);
		}
		ss << "Current pitch level is (press L to increase, K to decrease): " << pitch;
		_text->addLine(ss.str(), lastKnownRowIndex++);
		ss.str("");

		//Get the current reverb
		if (_channel)
		{
			_channel->getReverbProperties(1, &wet);
		}
		ss << "Current reverb (press M to raise, N to decrease): " << wet;
		_text->addLine(ss.str(), lastKnownRowIndex++);
		ss.str("");

		//Mute
		if (_channel)
		{
			_channel->getMute(&isMuted);
		}
		ss << "Is channel muted (press Q to toggle): " << ((isMuted) ? "Yes" : "No");
		_text->addLine(ss.str(), lastKnownRowIndex++);
		ss.str("");

		//Volume Ramp
		if (_channel)
		{
			_channel->getVolumeRamp(&wantToRamp);
		}
		ss << "Should we ramp the volume? (press Z to toggle): " << ((wantToRamp) ? "Yes" : "No");
		_text->addLine(ss.str(), lastKnownRowIndex++);
		ss.str("");

		_text->addLine("-------------------------------------------------------", lastKnownRowIndex++);
		_text->addLine("Press ESC to exit.", lastKnownRowIndex++);

		_text->render();

		glfwSwapBuffers(_window);
		glfwPollEvents();
	} //end of while

	shutdown();
} //end of main


//Function Definitions
bool init()
{
	if (!initGLFW())
	{
		return false;
	}
	if (!initGL())
	{
		return false;
	}

	_text = new RSS::GLText(_appName, _windowWidth, _windowHeight);

	if (!initFMOD())
	{
		return false;
	}

	return true;
} //end of init

bool initGLFW()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Unable to initialize GLFW");
		return false;
	}

	//set error callbacks
	glfwSetErrorCallback(glfw_error_callback);

	_window = glfwCreateWindow(_windowWidth, _windowHeight, _appName.c_str(), NULL, NULL);
	if (!_window)
	{
		fprintf(stderr, "Unable to create GLFW window");
		return false;
	}

	glfwSetKeyCallback(_window, glfw_key_callback);
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(1);

	return true;
} //end of initGLFW

bool initGL()
{
	if (!gladLoadGL(glfwGetProcAddress))
	{
		fprintf(stderr, "Unable to initialize GLAD");
		return false;
	}

	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	return true;
} //end of initGL

bool initFMOD()
{
	_result = FMOD::System_Create(&_system);
	if (_result != FMOD_OK)
	{
		fprintf(stderr, "Unable to create FMOD system");
		return false;
	}

	_result = _system->init(32, FMOD_INIT_NORMAL, NULL);
	//_result = _system->init(32, FMOD_INIT_3D_RIGHTHANDED, NULL);
	if (_result != FMOD_OK)
	{
		fprintf(stderr, "Unable to initialize FMOD system");
		return false;
	}

	//This is where we would make the sounds
	if (!loadSounds())
	{
		fprintf(stderr, "Something went wrong with sounds");
		return false;
	}

	return true;
} //end of initFMOD

void shutdown()
{
	glfwTerminate();

	//release sounds
	for (unsigned int index = 0; index != _sounds.size(); index++)
	{
		_sounds[index]->release();
	}

	_result = _system->close();
	if (_result != FMOD_OK)
	{
		fprintf(stderr, "Unable to close system");
	}

	_result = _system->release();
	if (_result != FMOD_OK)
	{
		fprintf(stderr, "Unable to release system");
	}

	if (_text) {
		delete _text;
		_text = nullptr;
	}

	exit(EXIT_SUCCESS);
} //end of shutdown

//loadSounds locates and goes through the file "audioLists.txt" located within the audio folder within the assets folder
//within the common folder on the solution level.  While going through the file, we attempt to add the audio file
//by name in the audio folder
bool loadSounds()
{
	std::stringstream ss;
	std::stringstream sFile;
	ss << SOLUTION_DIR << "common\\assets\\audio\\audioList.txt";
	std::ifstream theFile(ss.str());
	//testing
	//std::cout << ss.str().c_str() << std::endl;
	//std::cout << theFile.is_open() << std::endl;

	if (!theFile.is_open())
	{
		fprintf(stderr, "Could not open audioList.txt");
		return false;
	}
	std::string nextToken;

	FMOD::Sound* sound = NULL;
	ss.str("");
	//Scan until we find the word "end"
	while (theFile >> nextToken)
	{
		//std::cout << "nextToken: " << nextToken.c_str() << std::endl;	//testing
		//if we reach the end token we leave the while loop
		if (nextToken == "end")
		{
			break;
		} //end if
		//if the string nextToken contains .mp3 or .wav (added .mp4, .m4a and .m4p) we have reached the end of the file name and can attempt to add the sound
		//|| nextToken.find(".mp4") != std::string::npos || nextToken.find(".m4a") != std::string::npos || nextToken.find(".m4p") != std::string::npos
		if (nextToken.find("mp3") != std::string::npos || nextToken.find("wav") != std::string::npos)
		{
			sFile << nextToken.c_str();
			ss << SOLUTION_DIR << "common\\assets\\audio\\" << sFile.str().c_str();	//path including audio file name
			songNames.push_back(sFile.str().c_str());
			//std::cout << "ss: " << ss.str().c_str() << std::endl;		//testing
			_result = _system->createSound(ss.str().c_str(), FMOD_LOOP_OFF, 0, &sound);						//attempt to create the sound
			if (_result != FMOD_OK)
			{
				fprintf(stderr, "Unable to create a sound");
			} //end if
			else
			{
				_sounds.push_back(sound);	//add the sound to our smart array _sounds
			} //end else
			ss.str("");
			sFile.str("");
		} //end if
		else
		{
			//this is in case the audio file name contains spaces, there are other whitespace characters, but we are going to use newline or space to indicate the end of a file
			sFile << nextToken.c_str() << " "; //add the nextToken to sFile and add a space because we didn't read an extension yet
		} //end else
	} //end while
	theFile.close();
	return true;
} //end of loadSounds