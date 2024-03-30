; for(Queue tmp = qu; !tmp.Empty(); tmp.Pop()) cout << tmp.Front() << ' '; cout << endl;
    qu.Push(6); for(Queue tmp = qu; !tmp.Empty(); tmp.Pop()) cout << tmp.Front() << ' '; cout << endl;
    qu.Push(9); for(Queue tmp = qu; !tmp.Empty(); tmp.Pop()) cout << tmp.Front() << ' '; cout << endl;
    qu.Pop(); for(Queue tmp = qu; !tmp.Empty(); tmp.Pop()) cout << tmp.Front() << ' '; cout << endl;
    qu.Pop(); for(Queue tmp = qu; !tmp.Empty(); tmp.Pop()) cout << tmp.Front() << ' '; cout << endl;
    qu.Push(10); for(Queue tmp = qu; !tmp.Empty(); tmp.Pop()) cout << tmp.Front() << ' '; cout << endl;
    cout << qu.Size() << endl;
    cout << qu.Front() << endl; 
    cout << qu