# 카이사르 암호 변환기
## 0. 개요
* 카이사르 암호란 암호화하고자하는 문자를 알파벳기준 몇 글자씩 밀어서 다른 알파벳으로 치환하는 방식이다
* ex) **"ABC" -> 3번 쉬프트 -> "DEF"**
* 내가 ABC라는 단어를 누군가에게 비밀리에 보내고 싶을때 이런식으로 암호화하여 보내고 상대도 몇글자를 쉬프트했는지 규칙을 안다는 가정하에 해독할 수 있다.
## 1. 프로그램 설명
* 원래의 이 카이사르 암호를 조금 변형시켜 몇글자씩 미루자는 규칙을 암호화하는쪽에서 정하고 이 규칙을 암호한 문자에 포함시켜 보낸다.
* ex) **"abc" -> 1번 쉬프트 -> "bcdb"**
* bcd는 변환된 실제 내용이고 맨마지막 문자는 a=0, b=1,... 쉬프트 된 횟수를 정의한다.

```c
void encoder(const char* , int);

void decoder(const char* );
```
* encoder : 암호화하고 싶은 문자열(const char*)과 몇 번 쉬프트(int)하여 암호화할지를 인자로 받아 암호화된 문장을 출력한다
* decoder : 암호화된 문자열(const char*)을 원본 문자열로 해독하여 출력한다.

## 2. 빌드 및 테스트 과정
### static Library
```bash
gcc -c caesar_cipher.c # caesar_cipher.o 생성
ar -r libcaesar.a caesar_cipher.o # libcaesar.a 생성
```

### Shared Library
```bash
gcc -c -fpic caesar_cipher.c # caesar_cipher.o 생성 (position-independent가 포함됨)
gcc -shared -o libcaesar.so caesar_cipher.o # libcaesar.so 생성
gcc test.c -L. -lcaesar # test.c와 liacaesar.so를 링킹하여 실행파일 생성
./a.out # 실행
```
<img width="457" alt="스크린샷 2024-11-29 오전 12 00 10" src="https://github.com/user-attachments/assets/77e50b1f-551d-4fd7-b187-272296161e2a">

### Run-Time Linking
```bash
gcc -rdynamic -o runtime test_run_time.c -ldl # run-time linking용 실행파일 생성
./runtime # 실행
```
<img width="452" alt="스크린샷 2024-11-29 오전 12 14 08" src="https://github.com/user-attachments/assets/7c6f0005-e639-43f1-8786-123b4f9cbf06">
