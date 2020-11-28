package kr.co.gracegirls.tmi.module;

import android.content.Context;
import android.util.AttributeSet;
import android.view.View;
import android.widget.ImageButton;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.constraintlayout.widget.ConstraintLayout;

import kr.co.gracegirls.tmi.R;

public class TitleBar extends ConstraintLayout {

    View view;
    public ImageButton backButton;

    public TitleBar(@NonNull Context context) {
        super(context);
    }

    public TitleBar(@NonNull Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        view = View.inflate(context, R.layout.view_title_bar, this);
    }

    public void init(String title, Boolean isBackPressed) {

        TextView titleText = findViewById(R.id.title_text);
        titleText.setText(title);

        backButton = findViewById(R.id.title_back_button);
        if (isBackPressed) {
            backButton.setVisibility(View.VISIBLE);
        } else {
            backButton.setVisibility(View.GONE);
        }
    }
}
