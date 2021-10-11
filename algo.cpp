
struct pt{
    int x, y;
};

int A,B;


bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
}

void convex_hull(vector<pt>& a) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}


bool isonPoly(vector<pt>& vert,  pt test) {

  vert.pb(test);
  convex_hull(vert);

  for(int i=0;i<sz(vert);i++)
  {
    if(vert[i].x==test.x&&vert[i].y==test.y)
      return true;
  }
 
  return false; 

}

ld peri(vector<pt>& v) 
{ 
    ld p = 0.0; 
    int j = sz(v) - 1; 
    for (int i = 0; i < sz(v); i++) 
    { 
        ld d = (v[j].x - v[i].x)*(v[j].x - v[i].x) + (v[j].y - v[i].y)*(v[j].y - v[i].y); 
        d=sqrt(d);
        p+=d;
        j = i;  
    } 
  
    return p;
} 