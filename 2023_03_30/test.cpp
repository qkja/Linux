#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return int整型
     */
    bool is_reply(std::string& str, int left, int right)
    {
        while (left < right)
        {
            if (str[left++] != str[right--])
                return false;
        }
        return true;

    }

    int minCut(string s) {
        if (s.empty())
            return 0;

        int len = s.size();
        std::vector<int> dp(len + 1, 0);

        for (int i = 2; i < len + 1; i++)
        {
            if (!is_reply(s, 0, i - 1))
            {
                int ret = dp[i - 1] + 1;
                for (int j = 1; j < i; j++)
                {
                    if (is_reply(s, j, i - 1))
                    {
                        ret = std::min(ret, dp[j] + 1);
                    }
                }
                dp[i] = ret;
            }
        }

        return dp[len];
    }
};















//class Solution {
//public:
//    /**
//     *
//     * @param s string字符串
//     * @return int整型
//     */
//    bool is_reply(std::string& str, int left, int right)
//    {
//        while (left < right)
//        {
//            if (str[left++] != str[right--])
//                return false;
//        }
//        return true;
//
//    }
//
//    int minCut(string s) {
//        if (s.empty())
//            return 0;
//
//        int len = s.size();
//        std::vector<int> dp(len+1, 0);
//
//        for (int i = 2; i < len + 1; i++)
//        {
//            if (!is_reply(s, 0, i-1))
//            {
//                int ret = dp[i-1] + 1;
//                for (int j = 1; j < i; j++)
//                {
//                    if (is_reply(s, j, i - 1))
//                    {
//                        ret = std::min(ret, dp[j + 1] + 1);
//                    }
//                }
//                dp[i] = ret;
//            }
//        }
//
//        return dp[len];
//    }
//};

//class Solution {
//public:
//    /**
//     *
//     * @param s string字符串
//     * @return int整型
//     */
//    bool is_reply(std::string& str, int i)
//    {
//        int left = 0;
//        int right = str.size() - 1;
//        while (left < right)
//        {
//            if (str[left++] != str[right--])
//                return false;
//        }
//        return true;
//
//    }
//    int minCut(string s) {
//        // write code here
//    }
//
//    //0到index 不再进行关心, 我们只需要 关心index后面是否是回文串
//    // 我们的切割次数
//    int process(std::string& str, int index)
//    {
//        if (str.size() == index)  // ab
//            return 0;
//        // 判断是否回文
//        if (is_reply(str, index) == true)
//            return 0;
//        else
//        {
//            return 1 + process(str, index + 1);
//        }
//    }
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	int maxVal(std::vector<int>& w, std::vector<int>& v, int bag)
//	{
//		// 参数判断
//		if (w.empty() || v.empty() || w.size() != v.size())
//			return -1;
//	}
//
//};
//
//int main() {
//	int n = 0;
//	std::cin >> n;
//	std::vector<int> c(n, 0);  // 价值
//	std::vector<int> w(n, 0);  // 重量
//	int bag = 0;
//	std::cin >> bag;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> c[i] >> w[i];
//	}
//	std::cout << Solution().maxVal(w, c, bag) << std::endl;
//
//	return 0;
//}
