# 0 "/home/dominik/Projects/prlgruzracer/src/core/main.cpp"
# 1 "/home/dominik/Projects/prlgruzracer/build//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/dominik/Projects/prlgruzracer/src/core/main.cpp"
# 1 "/home/dominik/Projects/prlgruzracer/src/core/game.h" 1
       

# 1 "/home/dominik/Projects/prlgruzracer/src/common/singleton.h" 1
       

template <typename T>
class Singleton
{
    public:
        Singleton() = default;
        Singleton(const Singleton &other) = delete;

        static T* GetInstance()
        {
            static T* _instance;
            return _instance;
        }
};
# 4 "/home/dominik/Projects/prlgruzracer/src/core/game.h" 2

class CGame : public Singleton<CGame>
{
    friend class Singleton<CGame>;

    public:
        void Start();
        void Update();
        void End();

        void BeginFrame();
        void EndFrame();

    private:
        CGame() = default;
};
# 2 "/home/dominik/Projects/prlgruzracer/src/core/main.cpp" 2

int main()
{
    CGame *game = CGame::GetInstance();

    game->Start();
    game->Update();
    game->End();
}
