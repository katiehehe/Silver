//
// Created by Katie He on 6/24/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    vector<ll> usb;
    vector<ll> ps;
    for(int i = 0; i < m; ++i)
    {
        ll x;
        string s;
        cin >> x >> s;
        if(s == "USB")
        {
            usb.push_back(x);
        }
        else
        {
            ps.push_back(x);
        }
    }
    sort(usb.begin(), usb.end());
    sort(ps.begin(), ps.end());
    ll totalCost = 0;
    int totalComps = 0;
    int usbIndex = 0;
    int psIndex = 0;
    while(usbIndex < usb.size() && usbIndex < a)
    {
        totalCost += usb[usbIndex];
        ++totalComps;
        ++usbIndex;
    }
    while(psIndex < ps.size() && psIndex < b)
    {
        totalCost += ps[psIndex];
        ++totalComps;
        ++psIndex;
    }
    while(totalComps < m && c > 0)
    {
        if(usbIndex == usb.size())
        {
            totalCost += ps[psIndex];
            ++psIndex;
        }
        else if(psIndex == ps.size())
        {
            totalCost += usb[usbIndex];
            ++usbIndex;
        }
        else if(usb[usbIndex] <= ps[psIndex])
        {
            totalCost += usb[usbIndex];
            ++usbIndex;
        }
        else
        {
            totalCost += ps[psIndex];
            ++psIndex;
        }
        ++totalComps;
        --c;
    }
    cout << totalComps << " " << totalCost << endl;
}