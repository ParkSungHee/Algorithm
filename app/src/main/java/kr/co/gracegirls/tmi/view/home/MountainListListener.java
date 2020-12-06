package kr.co.gracegirls.tmi.view.home;

/*
 * Created by JJJoonngg
 */

import java.util.ArrayList;

import kr.co.gracegirls.tmi.data.item.MountainListItem;
import kr.co.gracegirls.tmi.data.item.ShelterListItem;

public interface MountainListListener {

    void setMountainList(ArrayList<MountainListItem> mountainListItems);

    void setShelterList(ArrayList<ShelterListItem> shelterListItems);
}
