#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <Audioclient.h>
#include <audiopolicy.h>

#define SAFE_RELEASE(punk)  \
if ((punk) != NULL)  \
{ (punk)->Release(); (punk) = NULL; }

#define MAX_VOL 100
class VolumeCtrl
{
public:
	VolumeCtrl(void);
	~VolumeCtrl(void);
	int GetVolume();
	BOOL GetMute();
	BOOL SetVolume(int nVol);
	BOOL SetMute(BOOL bMute);
	int SetSessionMute(int PID,BOOL bMute);

protected:
	BOOL InitCOM();
	BOOL UninitCOM();
	void InitController(); //��ȡĬ������豸���ս�㡢session����
	void ReleaseController();

	IMMDeviceEnumerator *m_pEnumerator; //ö����Ƶ�豸
	IMMDevice *m_pSpeaker; 
	IAudioEndpointVolume *m_pEndptVolCtrl; //��Ƶ�ս��
	IAudioSessionManager2 *m_pSessionManager; //��Ƶsession����	
	GUID m_guidMyContext; //GUID? ��֪����
};